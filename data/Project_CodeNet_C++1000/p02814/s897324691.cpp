#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int gcd(int a, int b) {
  return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a,ll b) {
  return a * b / gcd(a, b);
}int main() {
    int N,M;cin>>N>>M;
    vi a(N);
    for (int i = 0; i < N; i++){
        cin>>a[i];
        a[i]/=2;
    }
    int LCM=a[0];
    for (int i = 1; i < N; i++){
        LCM=lcm(LCM,a[i]);
        if(LCM>M){
            cout<<0<<endl;
            return 0;
        }
    }
    for (int i = 0; i < N; i++){
        if(LCM/a[i]%2==0){
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=(M/LCM+1)/2;
    cout<<ans<<endl;
}