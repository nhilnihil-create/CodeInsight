#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n;
	cin >> n;
	v1 c(0);
	map<string, pair<int, int>> q;//はじめがばしょ、次がカウント
	vector<string> sal(0);
	int j = 0;
	rep(i, n){
		string s;
		cin >> s;
		if(q.find(s) == q.end()){
			q[s] = make_pair(j, 1);
			c.push_back(1);
			sal.push_back(s);
			j++;
		}else{
			q[s].second ++;
			c.at(q[s].first)++;
		}
	}
	int f = sal.size();
	int g = c.size();
	if(f != g) cout << "error" << endl;
	set<string> answer;
	int max = 0;
	rep(i, f){
		if(c.at(i) > max){
			answer.erase(answer.begin(), answer.end());
			answer.insert(sal.at(i));
			max = c.at(i);
		}else if(c.at(i) == max){
			answer.insert(sal.at(i));
		}
	}
	int h = answer.size();
	auto itr = answer.begin();
	rep(i, h){
		cout << *itr << endl;
		itr++;
	}
}
