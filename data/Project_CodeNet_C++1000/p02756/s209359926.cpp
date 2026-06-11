//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef long long              ll;
typedef long double            ld;
typedef pair<int, int>         pi;
typedef vector<int>            vi;
typedef vector<pair<int, int>> vpi;

#define pb       push_back
#define pf       push_front
#define all(x)   begin(x), end(x)
#define sz(x)    (int)(x).size()
#define ff       first
#define ss       second
#define mp       make_pair
#define lb       lower_bound
#define ub       upper_bound
#define tcase()  int t; cin >> t; while(t--)

const int MOD = 1e9 + 7; // 998244353;
const int MX  = 2e5 + 5;
const ll  INF = 1e18;
const ld  PI  = acos((ld) -1);

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){

    setIO();

    string s;
    cin >> s;

    int q;
    cin >> q;

    deque<char> d;

    for(int i = 0; i < sz(s); i++) d.pb(s[i]);

    bool f = true;

    while(q--){

        int a;
        cin >> a;

        if(a == 1) f = !f;
        else{

            int c;
            cin >> c;

            char b;
            cin >> b;

            if(c == 1){
                if(f) d.pf(b);
                else d.pb(b);
            }
            else{
                if(f) d.pb(b);
                else d.pf(b);
            }
        }
    }

    if(f){
        while(!d.empty()){
            cout << d.front();
            d.pop_front();
        }
    }
    else{
        while(!d.empty()){
            cout << d.back();
            d.pop_back();
        }
    }
}
