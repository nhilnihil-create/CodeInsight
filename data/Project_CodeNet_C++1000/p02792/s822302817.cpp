#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;

unsigned GetDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

int c[10][10];
int dps[1000+1]; //体力hのときの最小消費魔力
int main(){
  int n;
  cin>>n;

  rep1(k,n){
    int i2=k%10;
    int i1=k;
    while(i1>=10){
      i1=i1/10;
    }
    c[i1][i2]++;
  }
  int ans=0;
  rep(i,10){
    rep(j,10){
      ans+= c[i][j]*c[j][i];
    }
  }

  cout<<ans<<endl;


}
