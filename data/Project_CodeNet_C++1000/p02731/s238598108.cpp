#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<string> vsi;
typedef map<ll, ll> mape;
#define rep(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define per(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define N 2100
#define MAX 1000000000001
#define f first
#define s second
#define pb push_back
#define mkp make_pair
#define MOD 1000000007

int main()
{
    fastio;

    clock_t tStart = clock();

    ll n;
    cin >> n;
    double S = (double)n;
    cout << fixed << setprecision(10);
    cout << S*S*S / 27.00 << endl;

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
