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
  rep(i,25){
    rep(j,25){
      rep(k,25){
        rep(l,25){
          rep(m,25){
            rep(n,25){
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