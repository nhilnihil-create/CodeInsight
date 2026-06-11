#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo 1e18
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vs vector<string>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

const long double Pi=acos(-1),e=2.718;
const int N=3e3+10,mod=998244353;

int main ()
{
    FASTIO;
    ll h1 , m1 , h2 , m2 , k ;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    ll mn = h1*60 + m1;
    ll mn2 = h2*60+m2;
    cout << mn2 - mn - k << endl;
    return 0;
}
/**


*/
