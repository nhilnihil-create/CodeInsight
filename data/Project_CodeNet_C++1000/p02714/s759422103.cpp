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

//b以上の最初の要素の位置を返す。ない場合(すべてがb未満の場合)はv.size()を返す
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
	else return v.size();
}

//bより大きいの最初の要素の位置を返す。ない場合(すべての要素がb以下の場合)はv.size()を返す
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
	else return v.size();
}


long long N;
string S;
vector<long long> R, G, B;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N ;
	cin >> S ;

	for(long long i=0; i<S.size(); i++){
		char c = S[i];
		if(c == 'R') R.push_back(i);
		if(c == 'G') G.push_back(i);
		if(c == 'B') B.push_back(i);
	}

	if(R.size() == 0 || G.size() == 0 || B.size() == 0){
		printf("0\n");
		return 0;
	}

	//jを軸に考える
	long long ans = 0;
	for(long long j = 1; j < N - 1; j++){
		char c = S[j];
		long long na, nb;
		if(c == 'R'){
			na   = lbound(G, j);
			nb   = B.size() - ubound(B, j);
			ans += na * nb;
			na   = lbound(B, j);
			nb   = G.size() - ubound(G, j);
			ans += na * nb;
		}
		if(c == 'G'){
			na   = lbound(R, j);
			nb   = B.size() - ubound(B, j);
			ans += na * nb;
			na   = lbound(B, j);
			nb   = R.size() - ubound(R, j);
			ans += na * nb;
		}
		if(c == 'B'){
			na   = lbound(G, j);
			nb   = R.size() - ubound(R, j);
			ans += na * nb;
			na   = lbound(R, j);
			nb   = G.size() - ubound(G, j);
			ans += na * nb;
		}
		//jがiとkの中点になっているものを数えて引く。
		for(int i=1; ; i++){
			if(j - i < 0 || j + i >=N) break;
			char c1 = S[j - i];
			char c2 = S[j + i];
			if(c1 != c && c2 != c && c1 != c2){
				ans--;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}