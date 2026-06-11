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


    ll n, m, k;
    cin>> n>> m>> k;

    if( k> n)
    {
        m= max( 0LL, m+ n-k );
        n= 0;
    }
    else
    n= n-k;


    // m= max (0LL , m+ min (0LL, n-k) );
    //n= max (0LL, n-k);


    cout << n <<" " <<m << '\n';

    return 0;
}

