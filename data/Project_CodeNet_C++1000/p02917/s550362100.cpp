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
   vector<int>A(N);
   vector<bool>C(N);
   vector<int>B(N-1);
   rep(i,N-1){
       cin>>B[i];
       if(C[i]==false){
           C[i]=true;
           A[i]=B[i];
       }
       if(C[i+1]==false){
           C[i+1]=true;
           A[i+1]=B[i];
       }
       if(B[i]<A[i]){
           A[i]=B[i];
       }
       if(B[i]<A[i+1]){
           A[i+1]=B[i];
       }
   }
   int ans=0;
   rep(i,N){
       ans+=A[i];
   }
   cout<<ans<<endl;
}