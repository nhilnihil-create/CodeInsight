#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans*=(A-i);
    }
    for (int i = 0; i < B; i++) {
        ans /=i+1;
    }
    return ans;
}
int main(){
    int N;
    cin>>N;
    vector<int>X(N);
    int a=100000;
    int b=0;
    rep(i,N){
        cin>>X[i];
        if(X[i]<a){
            a=X[i];
        }
        else if(b<X[i]){
            b=X[i];
        }
    }
    int ans=100000000;
  	bool d=false;
    for(int i=a; i<b+1; i++){
        int cnt=0;
        rep(j,N){
            cnt+=abs(i-X[j])*abs(i-X[j]);
        }
        if(cnt<ans){
            ans=cnt;
          d=true;
        }
    }
  if(d==true){
    cout<<ans<<endl;
  }
  else{
    cout<<0<<endl;
  }
}
