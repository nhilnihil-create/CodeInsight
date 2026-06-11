#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    auto up = [](int x){
        int res = 0;
        while(x){
            res = x%10;
            x /= 10;
        }
        return res;
    };

    vvec<ll> cnt(10,vec<ll>(10));
    for(int i=1;i<=N;i++){
        cnt[up(i)][i%10]++;
    }
    ll ans = 0;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++){
        ans += cnt[i][j]*cnt[j][i];
    }
    cout << ans << "\n";
}