#include<bits/stdc++.h>
 using namespace std;
 
 // #define  int           long long
 #define pb                push_back
 #define ppb               pop_back
 #define pf                push_front
 #define ppf               pop_front
 #define all(x)            (x).begin(),(x).end()
 #define uniq(v)           (v).erase(unique(all(v)),(v).end())
 #define sz(x)             (int)((x).size())
 #define fr                first
 #define sc                second
 #define pint              pair<int,int>
 #define rep(i,a,b)        for(int i=a;i<b;i++)
 #define mem1(a)           memset(a,-1,sizeof(a))
 #define mem0(a)           memset(a,0,sizeof(a))
 #define ppc               __builtin_popcount
 #define ppcll             __builtin_popcountll
 #define vint			   vector<int>
 #define vpint			   vector<pair<int,int>>
 #define mp                make_pair


 void reader() 
 { 
 #ifndef ONLINE_JUDGE 
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout); 
 #endif
 }
 
 void fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}
 
 
 
 void solve()
 {
 int n;
 cin>>n;
 n-=400;
int i=n/200;
cout<<8-i;
 
 
 
 cout<<"\n";
 }
 
 
 
 signed main()
 {
 	reader(); fastIO();
 	long long t=1;
 	//cin>>t;
 	while(t--) solve();
 	return 0;
 }