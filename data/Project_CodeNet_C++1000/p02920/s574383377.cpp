/*
Problem : https://atcoder.jp/contests/abc140/tasks/abc140_f
Algorithm : simulate
Status :
*/
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

int n,mx;
multiset<int> a;
vector<int> v,tmp;

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < (1 << n);i++){
		int x;
		scanf("%d",&x);
		a.insert(x);
		mx = max(mx,x);
	}
	v.push_back(mx);
	a.erase(a.find(mx));
	for(int i = 1;i <= n;i++){
		tmp.clear();
		for(auto x : v){
			auto it = a.lower_bound(x);
			//cout << *it << endl;
			if(it == a.begin()){
				puts("No");
				return 0;
			}
			it--;
			tmp.push_back(*it);
			a.erase(it);
		}
		for(auto x : tmp)
		    v.push_back(x);
	}
	puts("Yes");
	return 0;
}