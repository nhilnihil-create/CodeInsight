#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,M,WA=0,AC=0;
  cin>>N>>M;
  vector<int> ac(N),wa(N);
  rep(i,M){
    int prob;
    string check;
    cin>>prob>>check;
    prob-=1;
    if(ac[prob])continue;
    if(check=="AC"){
      ac[prob]=1;
    }else{
      wa[prob]+=1;
    }
  }
  rep(i,N){
    AC+=ac[i];
    if(ac[i])WA+=wa[i];
    //正解してない問題はペナにならんのではじく。
  }
  cout<<AC<<" "<<WA<<endl;
  return 0;
}