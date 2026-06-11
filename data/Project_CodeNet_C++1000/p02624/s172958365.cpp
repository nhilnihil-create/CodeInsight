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
#define MAX 10000001
#define f first
#define s second
#define pb push_back
#define mkp make_pair
#define MOD 1000000007

vi divi(MAX);

void sum(ll n)
{
    rep(i, 2, n) divi[i] *= i;
    rep(i, 2, n) divi[i] += divi[i-1];
}

int main()
{
    fastio;

    //clock_t tStart = clock();

    ll n;
    cin >> n;
    rep(i, 1, n){
        ll j = i;
        while(j <= n){
            divi[j]++;
            j += i;
        }
    }
    sum(n);
    cout << divi[n] << endl;

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
