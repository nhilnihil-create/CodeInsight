#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    rep(i,n){
        ll mi;
        cin >> mi;
        m[mi]++;
    }
    if (m.count(0) && m[0] == n){
        cout << "Yes" << endl;
        return 0;
    }

    if (n % 3 != 0){
        cout << "No" << endl;
        return 0;
    }

    if (m.size() == 2 && m.count(0) && m[0] == n/3){
        cout << "Yes" << endl;
        return 0;
    }
    else if (m.size() == 3){
        ll ans = 0;
        for(auto mi = m.begin(); mi != m.end(); mi++){
            if (mi->second != n/3){
                cout << "No" << endl;
                return 0;            
            }
            ans ^= mi->first;
        }
        if (ans == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
 
}