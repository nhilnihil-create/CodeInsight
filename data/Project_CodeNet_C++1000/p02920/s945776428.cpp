#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>

using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n = 1<<n;
    vector<int> a;
    multiset<int> st;
    rep(i, n) {
        int x;
        cin >> x;
        st.insert(x);
    }

    a.push_back(*prev(st.end()));
    auto itr = st.end();
    --itr;
    st.erase(itr);
    while(st.size()) {
        vector<int> b = a;
        for(auto x : a) {
            auto itr = st.lower_bound(x);
            if(itr==st.begin()) {
                cout << "No" << endl;
                return 0;
            }
            --itr;
            b.push_back(*itr);
            st.erase(itr);
        }
        b.swap(a);
    }
    cout << "Yes" << endl;
    return 0;
}