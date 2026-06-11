#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    map<int, int> mp;
    rep(i, N){
        mp[a[i]]++;
    }
    if(mp.size() == 1 && mp.count(0)){
        cout << "Yes" << endl;
        return 0;
    }
    if(N % 3 != 0){
        cout << "No" << endl;
        return 0;
    }
    if(mp.size() == 2){
        if(!mp.count(0)){
            cout << "No" << endl;
            return 0;
        }
        if(mp[0] != N / 3){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        return 0;
    }
    if(mp.size() != 3){
        cout << "No" << endl;
        return 0;
    }
    vector<bitset<100>> bs;
    for(auto m: mp){
        if(m.second != N / 3){
            cout << "No" << endl;
            return 0;
        }
        bs.push_back(m.first);
    }
    if((bs[0]^bs[1]) == bs[2]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}






// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
