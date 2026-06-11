/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
int a[106];
vector<int> v[100005];
vector<int> vis(100005);
map<ll,ll> mp;
int gcd(int x, int y)
{                     
        return (x==0)? y : gcd(y % x, x);
}
void dfs(int node){
	 vis[node]= 1;
	 for(auto child : v[node]){
	 	if(!vis[child])
	 	   dfs(child);
	 }
}
int main(){
   int N , M ;
   cin >> N >> M ;
   for(int i = 0 ; i < M ; i++){
   	     int x , y ; 
		cin >> x >> y ;
   	    v[x].push_back(y);
   	    v[y].push_back(x);
   }
   ll count =0;
   for(int i = 1 ; i <=N ; i++){
   	   if(!vis[i])
   	   {
   	   	    dfs(i);
   	   	    count++;
		  }
   }
   cout << (count -1) << endl;
}
