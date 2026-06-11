#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    int N;
    cin>>N;
    vector<int>p(N);
    int ans=0;
    rep(i,N){
        cin>>p[i];
    }
    rep(i,N){
        if(i==0||i==N-1){
        }
        else{
            if(p[i]<p[i-1]&&p[i+1]<p[i]){
                ans++;
            }
            else if(p[i]<p[i+1]&&p[i-1]<p[i]){
                ans++;
            }
        }
    }
        cout<<ans<<endl;
    
}
