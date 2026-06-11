#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

//b以上の最初の要素の位置を返す。ない場合は-1
//vはソート済であること。あと、&v でなくvだと引数コピーが発生するので遅い。
//戻り値は b未満の要素の数である。
int lbound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] >= b){
			e = m;
		}
		else{
			s = m;
		}
	}
	if(v[max(s - 1, 0)] >= b) return max(s - 1, 0);
	else if(v[s] >= b) return s;
	else if(v[min(s + 1, l - 1)] >= b) return min(s + 1, l - 1);
	else return -1;
}

//bより大きいの最初の要素の位置を返す。ない場合は-1
//vはソート済であること。あと、&v でなくvだと引数コピーが発生するので遅い。
//戻り値は b以下の要素の数である。
int ubound(vector<long long>&v, long long b){
	int s = 0, e = v.size() - 1;
	int l = v.size();
	int m;
	while(e - s > 1){
		m = (s + e) / 2;
		if(v[m] <= b){
			s = m;
		}
		else{
			e = m;
		}
	}
	if(v[max(s - 1, 0)] > b) return max(s - 1, 0);
	else if(v[s] > b) return s;
	else if(v[min(s + 1, l - 1)] > b) return min(s + 1, l - 1);
	else return -1;
}

long long N, M;

vector<pair<long long, long long>> V; // (金額,　日数)
map<long long, vector<long long>> MP;  //(日数, vector<金額>)
vector<long long> D; //vector<distinct(日数)>
map<long long, int> MONEY; //ワーク用、金額を入れていく。

long long getMaxMoney(){
	long long ret = 0;
	long long m;
	int d;
	if(MONEY.size() == 0){
		return 0;
	}
	else if(MONEY.size() == 1){
		auto itr = MONEY.begin();
		m = itr->first;
		d = itr->second;
		if(d > 0){
			ret = m;
			MONEY[m]--;
			if(MONEY[m] == 0){
				MONEY.erase(itr); //itr = MONEY.end()のはず
			}
		}
	}
	else{
		for(auto itr = MONEY.crbegin(); itr != MONEY.crend(); itr++){
			m = itr->first;
			d = itr->second;
			if(d == 0){
				continue;
			}
			if(d > 0){
				ret = m;
				MONEY[m]--;
				if(MONEY[m] == 0){
					MONEY.erase(MONEY.find(m));
				}
			}
			break;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M ;
	for(int i=0; i<N; i++){
		long long a, b;
		cin >> a >> b; //日数, 金額
		pair<long long, long long> p = make_pair(b, a);
		V.push_back(p);
	}
	sort(V.begin(), V.end());

	for(int i=0; i<N; i++){
		pair<long long, long long> p = V[i];
		long long m = p.first;
		long long d = p.second;
		MP[d].push_back(m);
	}

	for(auto itr = MP.begin(); itr !=MP.end(); itr++){
		long long d = itr->first;
		D.push_back(d);
	}

	//M日後から逆にたどる
	//M日後のi日前に受けるバイトは、i日以下の日数で金額が最大のもの
	long long ans = 0;
	int dp[100002] = {0};
	for(int i=1; i<=M; i++){
		long long d = ubound(D, i);
		if(d == 0) continue;
		if(d < 0){
			d = D.size();
		}

		vector<long long> &v = MP[D[d - 1]];
		if(dp[D[d - 1]] == 0){
			for(int j=0; j<v.size(); j++){
				long long w = v[j];
				if(MONEY.count(w)==0){
					MONEY[w] = 1;
				}
				else{
					MONEY[w]++;
				}
			}
		}
		ans += getMaxMoney();
		dp[D[d - 1]] = 1;
	}
	printf("%lld\n", ans);
	return 0;
}