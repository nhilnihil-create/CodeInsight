#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int>alo(N);
    rep(i, 0, N){
        if (S[i] == 'R') alo[i] = 0;
        if (S[i] == 'G') alo[i] = 1;
        if (S[i] == 'B') alo[i] = 2;
    }
    vector<ll>cnt(3);
    rep(i, 0, N)cnt[alo[i]]++;
    ll ans = 1;
    rep(i, 0, 3)ans*=cnt[i];
    rep(j, 0, N){
        rep(i, 0, j){
            int k = j+(j-i);
            if (k<N) {
                if(alo[i] == alo[j])continue;
                if(alo[i] == alo[k])continue;
                if(alo[k] == alo[j])continue;
                ans--;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
