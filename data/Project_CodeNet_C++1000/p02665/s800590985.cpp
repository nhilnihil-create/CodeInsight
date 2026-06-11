#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int N;
  cin>>N;
  bool error=false;
  int64_t ans=0;
  vector<int64_t> S(N+1);
  vector<int64_t> T(N+1);
  for(int i=0;i<=N;i++)cin>>S.at(i);
  T.at(N)=S.at(N);
  for(int i=N-1;i>0;i--) T.at(i)=T.at(i+1)+S.at(i);
  T.at(0)=1;
  for(int i=1;i<=N;i++){
    T.at(i)=min(T.at(i),2*T.at(i-1)-2*S.at(i-1));
    if(T.at(i)<1) error=true;
  }
  if(error||S.at(N)!=T.at(N)) cout<<-1;
  else{
    for(int i=0;i<=N;i++){
      ans+=T.at(i);
    }
    cout<<ans<<endl;
  }
 
}
