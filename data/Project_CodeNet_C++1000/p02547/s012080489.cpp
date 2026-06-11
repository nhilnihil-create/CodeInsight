#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll n,d[110][2];
  ll cnt=0;

  cin>>n;
  rep(i,n){
    rep(j,2){
      cin>>d[i][j];
    }
  }

  rep(i,n){
    if(d[i][0]==d[i][1]){
      cnt++;
      if(cnt==3){
        cout<<"Yes"<<endl;
        return 0;
      }
    }else{
      cnt=0;
    }
  }


  cout<<"No"<<endl;
  return 0;
}
