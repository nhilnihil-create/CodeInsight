#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    multiset<ll> st, st2;
    for(int i=0; i<(1<<N); i++){
        ll x; cin >> x;
        st.insert(x);
    }
    auto itr = st.end();
    itr--;
    st2.insert(*itr);
    st.erase(itr);

    bool ok = true;
    vector<ll> tmp;
    for(int i=0; i<N; i++){
        // debug(st);
        // debug(st2);
        if(!ok) break;
        for(auto& x: st2){
            auto itr = st.lower_bound(x);
            if(itr == st.begin()){
                ok = false; break;
            }
            itr--;
            tmp.push_back(*itr);
            st.erase(itr);
        }
        for(auto& x: tmp) st2.insert(x);
        tmp.clear();
    }

    if(ok) cout << "Yes\n";
    else cout << "No\n";
}