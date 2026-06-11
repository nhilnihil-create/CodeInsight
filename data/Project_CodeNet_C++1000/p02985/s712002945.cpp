#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int mod = 1000000007;
vector<int> v[MAX];

long long int dfs(int now,int from,int color){
  int canuse;
  if(from==-1)canuse=color-1;
  else{canuse=color-2;}
  if(color<(int)v[now].size())return 0;
  else{
  long long int co_no_iro = 1;
	for (int i=0;i<(int)v[now].size();i++){
    if(v[now].at(i)==from)continue;
    else{
		co_no_iro *= canuse;
    canuse--;
    co_no_iro %= mod;
		}}
 	for (int i=0;i<(int)v[now].size();i++){
    if(v[now].at(i)==from)continue;
    else{
		co_no_iro *= dfs(v[now].at(i),now,color);
    co_no_iro %= mod;
		}}
  return co_no_iro;
	}
}
int main(){
  int N,K;
	cin >> N >> K;
  int a,b;
  long long int ans =0;
	for(int i=0;i<N-1;i++){
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	ans = K * dfs(0,-1,K);
  ans %= mod;
	cout<< ans <<endl;
}