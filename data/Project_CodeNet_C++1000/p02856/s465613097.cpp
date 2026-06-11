#include <bits/stdc++.h>
#define INF 1e7
#define mod 1000000007

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;


int main()
{
    ll M; cin >> M;
    ll S = 0;
    ll N = 0;
    for(int i = 0; i < M; i++)
    {
        ll c,d; cin >> d >> c;
        S += c*d;
        N += c;
    }
    ll last = S % 9;
    if(last == 0) last = 9;
    ll b = 9*N+S;
    ll e = 9+last;
    ll ans = (b-e)/9;
    cout << ans << endl;
}