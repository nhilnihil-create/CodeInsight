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
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll ans = a*c;
    ans = max(ans,a*d);
    ans = max(ans,b*c);
    ans = max(ans,b*d);
    cout << ans << endl;
}