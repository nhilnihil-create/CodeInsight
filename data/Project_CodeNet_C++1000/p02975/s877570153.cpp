#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
map<ll, ll> ree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        ll x;
        cin >> x;
        ree[x]++;
    }
    if(ree.size() > 3){
        cout << "No\n";
    } else if(ree.size() == 3){
        pll a = *ree.begin(), b=*(++ree.begin()), c=*(++(++ree.begin()));
        //cout << a.f << " " << b.f << " " << c.f << "\n";
        //cout << (a.f ^ b.f ^ c.f) << "\n";
        if(a.s == b.s && a.s == c.s && (a.f^b.f^c.f) == 0){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    } else if(ree.size() == 2){
        pll a = *ree.begin(), b=*(++ree.begin());
        if(a.f == 0 && b.s==2*a.s){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    } else{
        if(ree.begin()->f == 0){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }

    return 0;
}
