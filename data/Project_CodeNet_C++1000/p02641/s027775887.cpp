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
    ll x,n,x1;
    cin>>x>>n;
    set<ll>s;
    fn(i,n) {
    cin>>x1;
    s.insert(x1);
    }

    if( s.find(x) == s.end()) {
        cout<<x<<endl;
        return;
    }

    ll i = 1;
    while(1)
    {
        ll tmp2 = x + i;
        ll tmp1 = x - i;

         if(s.find(tmp1) == s.end()) {
            cout<<tmp1<<endl; return;
        }
        else if(s.find(tmp2) == s.end()) {
               cout<<tmp2<<endl; return;
        }

        i++;

    }


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

