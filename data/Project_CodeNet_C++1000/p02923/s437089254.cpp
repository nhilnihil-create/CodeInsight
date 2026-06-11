#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();


    ll c= 0, mx= 0, n;

    cin>> n;

    ll h[n];

    cin>> h[0];
    for(int i=1; i<n; i++ )
    {
        cin>> h[i];

        if(h[i]> h[i-1])
        {
            if(mx< c)
            mx= c;
            c= 0;
        }
        else
            c++;
    }

    cout << (c> mx? c: mx);
    nl;


    return 0;
}



