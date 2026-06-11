#include <bits/stdc++.h>

using namespace std;
#define lli long long int
#define ff first
#define ss second
#define lld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef pair<int, int> pii;
typedef pair<long long int,long long int> pll;
const int nax=1000*1007;
#define INF 2e18
lli pow(lli x, lli y) { lli res = 1;while (y > 0) { if (y & 1) res = (res * x);  y = y >> 1; x = (x * x); } return res; } 


int main()
{
	IOS;
    int n;
    cin>>n;
    int co=0,mco=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
            co++;
        else
        {
            mco = max(mco,co);
            co=0;
        }
        
    }
    mco =max(mco,co);
    if(mco>=3)
        cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    
}