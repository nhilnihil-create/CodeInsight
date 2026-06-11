
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    REP(i, n) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int kosu = 0;
    bool flag = true;
    REP(i, n) {
        if(a[i] != 0) {
            flag = false;
        } else {
            kosu++;
        }
    }
    if(flag) {
        cout << "Yes" << endl;
        return 0;
    }

    if(n % 3 != 0) {
        cout << "No" << endl;
        return 0; 
    }

    if((st.size() == 2) && (kosu == n/3)) {
        int tmp = 0;
        REP(i, n) {
            if(a[i] != 0) {
                tmp = a[i];
            } 
        }
        REP(i, n) {
            if(a[i] != 0) {
                if(tmp != a[i]) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;
        return 0;
    }

    if(st.size() == 3) {
        int idx = 0;
        vector<int> tmp(3);
        for(auto i: st) {
            tmp[idx] = i;
            //cout << i << endl;
            idx++;
        }
        int x = 0, y = 0, z = 0;
        REP(i, n) {
            if(a[i] == tmp[0]) x++;
            else if(a[i] == tmp[1]) y++;
            else z++;
        }
        if((x == n/3) && (y == n/3) && (z == n/3)) {
            if((tmp[0] ^ tmp[1] ^ tmp[2]) == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }



    cout << "No" << endl;
    return 0;
}