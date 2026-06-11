#include<bits/stdc++.h>

//短縮
#define rep(i,n) for(int i=0;i<(n);++i)
//sort()用
#define all(v) v.begin(), v.end()

#define PB(N) push_back(N)

using namespace std;

using Graph = vector<vector<int>>;

int main(){
  int N,K; cin >> N >> K;
  vector<int> p(N);
  vector<double> v(N);

  rep(i,N){
    cin >> p[i];
  }
  rep(i,N){
    rep(j,p[i]){
      v[i]+=(j+1)/(double)p[i];
    }
  }

  //累積和をする
  rep(i,N){
    if(i==0)continue;
    v[i] += v[i-1];
  }
  double vmax=0;

  rep(i,N-K+1){
    if(i==0){
      if(vmax<v[i+K-1]) vmax=v[i+K-1];
    }
    else{
      if(vmax<v[i+K-1]-v[i-1]) vmax=v[i+K-1]-v[i-1];
    }
  }
  printf("%.7lf",vmax);

  return 0;
}
