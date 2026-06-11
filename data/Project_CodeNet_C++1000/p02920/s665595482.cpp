#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    multiset<int> rest;
    rep(i,pow(2,N)){
        int A;
        cin >> A;
        rest.insert(A);
    }
    auto it=rest.end();
    it--;
    multiset<int> done;
    done.insert(*it);
    rest.erase(it);
    rep(i,N){
        multiset<int> killed;
        for (auto x=done.begin();x!=done.end();x++){
            auto itr=rest.lower_bound(*x);
            if (itr==rest.begin()){
                cout << "No" << endl;
                return 0;
            }
            itr--;
            killed.insert(*itr);
            rest.erase(itr);
        }
        for (auto x=killed.begin();x!=killed.end();x++){
            done.insert(*x);
        }
    }
    cout << "Yes" << endl;
    return 0;
}