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

    string s;
    cin >> s;
    ll q;
    cin >> q;
    ll rev = 0;
    while(q--){
        ll type;
        cin >> type;
        if(type == 1) rev++;
        else{
            ll f;
            char ch;
            cin >> f >> ch;
            if(f == 1){
                if(rev%2) s += ch;
                else {
                    string t = ch + s;
                    s = t;
                }
            }
            else{
                if(rev%2) {
                    string t = ch + s;
                    s = t;
                }
                else s += ch;
            }
        }
    }
    if(rev%2) reverse(s.begin(), s.end());
    cout << s << endl;

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
