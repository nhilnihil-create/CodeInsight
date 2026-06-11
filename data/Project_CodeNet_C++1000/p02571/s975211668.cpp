#include<bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	 printf
#define sf			 scanf
#define pb(a)        push_back(a)
#define mp			 make_pair
#define ff			 first
#define ss			 second
#define for0(i,n)    for(int i=0;i<n;i++)
#define for1(i,n)    for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define sq(a)		 (a)*(a)
#define endl		     "\n"
#define abs(x)		 fabs(x)
#define all(v) 		 v.begin(),v.end()
#define pcase(z,x)   cout<<"Case "<<z<<": "<<x<<"\n"
#define mod 1000000007
#define WakandaForever     ios_base::sync_with_stdio(0); cin.tie(0);

int main()
{
    WakandaForever
    string s,t;
    cin>>s;
    cin>>t;
    int ans=t.size();
    for(int i=0 ; i<=(s.size()-t.size()) ; i++){
        int cnt=0;
        for(int j=0 ; j<t.size() ; j++){
            if(t[j]!=s[i+j]) cnt++;
        }
        ans = min(ans,cnt);
    }
    cout<<ans<<endl;

    return 0;
}
