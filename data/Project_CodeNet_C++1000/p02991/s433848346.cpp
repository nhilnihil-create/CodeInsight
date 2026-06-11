#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);


ll dist[100005][3];
vector<ll> adj[100005];

int main(){

	ll n,m;
	cin>>n>>m;
	ll aa,bb;
	fo(i,m){
		cin>>aa>>bb;
		adj[aa].pb(bb);
	}
	fo(i,100005){
		fo(j,3){
			dist[i][j]=10000000000000000;
		}
	}
	queue<ll> q;
	ll s,t;
	cin>>s>>t;
	dist[s][0]=0;
	q.push(s);
	bool can;
	while(!q.empty()){
		ll tmp=q.front();
		
		q.pop();
		for(auto j:adj[tmp]){
			    can=false;

			
				if(dist[j][1]>dist[tmp][0]+1){
					dist[j][1]=dist[tmp][0]+1;
					can=true;
				}
				if(dist[j][0]>dist[tmp][2]+1){
					dist[j][0]=dist[tmp][2]+1;
					can=true;
				}
				if(dist[j][2]>dist[tmp][1]+1){
					dist[j][2]=dist[tmp][1]+1;
					can=true;
				}
				if(can) q.push(j);
			    
		}
	}
	//dbg(dist[2][1]);
	if(dist[t][0]==10000000000000000) cout<<-1<<endl;
	else cout<<(dist[t][0]/3)<<endl;


}
