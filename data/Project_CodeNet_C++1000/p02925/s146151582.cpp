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


int main(){
	ll n;
	cin>>n;
	ll count[n+1];
	fo(i,n+1) count[i]=0;
	ll a[n+1][n];
	ll tmp;
	fo(i,n){
		fo(j,n-1){
			cin>>tmp;
			a[i+1][j]=tmp;
		}

	}
	unordered_map<ll,ll> mp;
	ll days=0;
	ll happen=false;
	ll node,check;
	bool there[n+1];
	fo(i,n+1) there[i]=false;
	while(true){
		happen=false;
		fo(j,n+1) there[j]=false;
		FOR(i,1,n){
			if(there[i]) continue;
			if(count[i]==n-1) continue;
			node=a[i][count[i]];
			//dbg2(i,node);
			if(a[node][count[node]]==i&&(!there[i])&&(!there[node])){
				count[node]++;
				count[i]++;
				happen=true;
				there[i]=true;
				there[node]=true;
			}

		}
		if(happen){
				days++;
			} 
		else break;


	}

    bool can=true;
	FOR(i,1,n){
		if(count[i]==n-1) ;
		else can=false;

	}
	if(can) cout<<days<<endl;
	else cout<<-1<<endl;


}