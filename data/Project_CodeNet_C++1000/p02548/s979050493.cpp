#include<bits/stdc++.h>

/*-------------------------------Template---------------------------------------*/

#define shameem              ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll                   long long int
#define gcd(a,b)              __gcd(a,b)
#define lcm(a,b)             (a*b)/gcd(a,b)
#define pi                    2*acos(0.0)
#define testi                int t; cin>>t; while(t--)
#define testl                ll t; cin>>t; while(t--)
#define vi                   vector<int>
#define vl                   vector<ll>
#define pb                   push_back
#define mk                   make_pair

/*-------------------------------Print---------------------------------------*/

#define YES                  cout<<"YES"<<endl
#define NO                   cout<<"NO"<<endl
#define yes                  cout<<"yes"<<endl
#define no                   cout<<"no"<<endl

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1; i<n; i++)
    {
        ans+=(n-1)/i;
    }
    cout<<ans<<endl;

}
int main()
{
    shameem

    //testi

    //testl



    solve();

    return 0;
}

