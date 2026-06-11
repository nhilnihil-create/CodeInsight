#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll,int> m;
    set<ll> s;
    REP(i,n){
        cin >> a[i];
        m[a[i]]++;
        s.insert(a[i]);
    }
    auto itr=s.begin();
    if(m.size()==1&&a[0]==0){
        cout << "Yes" << endl;
    }
    else if(n%3==0&&m.size()==3){
        ll x=*itr;
        ll a=m[*itr];itr++;
        ll y=*itr;
        ll b=m[*itr];itr++;
        ll z=*itr;
        ll c=m[*itr];
        ll tmp=x^y;
        if(a==b&&b==c&&tmp==z){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else if(n%3==0&&m.size()==2){
        ll x=*itr;
        ll a=m[*itr];itr++;
        ll y=*itr;
        ll b=m[*itr];
        if(x==0){
            if(b==a*2){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(y==0){
            if(a==b*2){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        cout << "No" << endl;
    }
}
