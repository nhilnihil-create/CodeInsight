#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  int N;
  cin>>N;
  vector<int> D(N);
  for(int i=0;i<N;i++){
    cin>>D.at(i);
  }
  if(D.at(0)!=0){
    cout<<0<<endl;
  }else{
    map<int,int> m;
    int k=0;
    for(int i=0;i<N;i++){
      if(m.count(D.at(i))==0){
        m[D.at(i)]=0;
      }
      m[D.at(i)]++;
      k=max(D.at(i),k);
    }
    if(m[0]>1){
      cout<<0<<endl;
    }else{
      ll ans=1;
      for(int i=1;i<=k;i++){
        for(int j=0;j<m[i];j++){
          ans*=(ll)m[i-1];
          ans%=MOD;
        }
      }
      cout<<ans<<endl;
    }

  }
}
