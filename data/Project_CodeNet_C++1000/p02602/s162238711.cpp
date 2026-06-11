		
#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ALL(a)              a.begin(), a.end()
#define ALLN(a, n)          (a, a+n)
#define MAX                 10000007
#define MIN                 -10000007



              
int main()
{
  ios::sync_with_stdio(0);
    cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
      
    int t;
    t=1;
     //  cin>>t;
    while(t--){
        	ll n,k;
        	cin>>n>>k;
        	ll a[n+1];
        	REP(i,1,n){cin>>a[i];}
        	REP(i,k+1,n){
        		if(a[i-k]<a[i])cout<<"Yes"<<"\n";
        		else cout<<"No"<<"\n";
        	}
       


             }
             cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}
