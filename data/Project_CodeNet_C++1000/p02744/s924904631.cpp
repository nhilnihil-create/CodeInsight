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
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

static char alp[27] = "abcdefghijklmnopqrstuvwxyz";

char findAlp(string &s){
	char ret;
	int C[27] = {0};
	for(int i=0; i<27; i++){
		C[i] = 0;
	}
	for(int i=0; i<s.size(); i++){
		unsigned char c = (unsigned char)s[i] - (unsigned char)'a' ;
		C[c]++;
	}
	for(int i=0; i<26; i++){
		if(C[i] == 0){
			ret = alp[i];
			break;
		}
	}
	return ret;
}

void dfs(int n, map<string, int> &v){
	if(n == 1){
		v.insert(make_pair("a", 1));
		return ;
	}
	if(n == 2){
		v.insert(make_pair("aa", 1));
		v.insert(make_pair("ab", 1));
		return ;
	}

	map<string, int> w = v;
	dfs(n - 1, w);
	for(auto itr = w.begin(); itr != w.end(); itr++){
		string s = itr->first;
		for(int j=0; j<s.size(); j++){
			string s1 = itr->first;
			//どれか1つと同じ場合
			s1.push_back(itr->first[j]);
			v.insert(make_pair(s1, 1));
			//どれとも異なる場合、sに含まれる文字以外の文字で最初のアルファベット
			string s2 = itr->first;
			char c = findAlp(s2);
			s2.push_back(c);
			v.insert(make_pair(s2, 1));
		}
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	map<string, int> M;
	dfs(N, M);

	for(auto itr = M.begin(); itr != M.end(); itr++){
		string s = itr->first;
		printf("%s\n", s.c_str());
	}
	return 0;
}
