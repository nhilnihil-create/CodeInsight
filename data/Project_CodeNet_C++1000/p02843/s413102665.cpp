#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int x;
  cin>>x;
  if(x>=2400){
    cout<<1<<endl;
    return 0;
  }
  for(int i=0;i<25;i++){
    for(int j=0;i+j<25;j++){
      for(int k=0;i+j+k<25;k++){
        for(int l=0;i+j+k+l<25;l++){
          for(int m=0;i+j+k+l+m<25;m++){
            for(int n=0;i+j+k+l+m+n<25;n++){
              if(i*100+j*101+k*102+l*103+m*104+n*105==x){
                cout<<1<<endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout<<0<<endl;
}