/*

                                  In the name of Allah, Most Gracious, Most Merciful


*/
#include<bits/stdc++.h>
#include<numeric>
using namespace std;

//*** constant value ***
const long double PI = 3.141592653589793238;
const double EPS = 1e-6 ;
//*** constant value ***

//****** define ********
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
#define vll vector<ll>
#define vs vector<string>
#define fn(i,n) for(ll i = 0; i<n; i++)
#define f(i,a,b) for(i=a;i<b;i++)
#define f1(i,a,b) for(i=b-1;i>=a;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pls pair<ll,string>
#define vpl vector<pll>
#define pb push_back
#define mk make_pair
#define x first
#define y second
#define tt cout<<"Came here"<<endl;
//****** define ********
void solve()
{
   ll n,k;
   cin>>n>>k;
   vll v(n);
   fn(i,n)
   cin>>v[i];
   sort(v.begin(),v.end());
   ll sum = 0;
   fn(i,k)
   sum += v[i];

   cout<<sum<<endl;

}

int main()
{
    IOS;
    ll tc = 1;
    while(tc--)
    {
        solve();
    }


return 0;
}

