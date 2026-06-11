#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> v(n,0);
    map<int,int> mii;
    rep(i,n){
        cin >> v[i];
        mii[v[i]]++;
    }
    if(mii.size() > 3){
        cout << "No" << endl;
        return 0;
    }
    if(mii.size() == 3){
        if(n%3 == 0){
            bool ok = 1;
            int now = 0;
            for(auto u : mii){
                if(u.second != n/3) ok = 0;
                now ^= u.first;
            }
            //cout << now << endl;
            if(ok && now == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    if(mii.size()  == 2){
        bool ok = 1;
        for(auto u : mii){
            if((u.second != n/3 && u.second != 2*n/3)) ok = 0;
            if(u.second == n/3 && u.first != 0) ok = 0;
            //if(u.second == 2*n/3 && u.first == 0) ok = 0;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if(mii.size() == 1){
        bool ok = 1;
        for(auto u : mii){
            if(u.first != 0) ok = 0;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    return 0;
}