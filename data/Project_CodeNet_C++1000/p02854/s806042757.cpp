#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++)  cin >> A.at(i);

  vector<long long> sum(N+1,0);
  for(int i=0;i<N;i++)  sum.at(i+1)=sum.at(i)+A.at(i);
  long long ans=1e18;
  for(int i=1;i<N;i++){
    if(sum.at(i)*2<sum.at(N)) continue;
    long long tmp=abs((sum.at(N)-sum.at(i))-sum.at(i));
    ans=min(ans,tmp);
  }
  for(int i=1;i<N;i++){
    if(sum.at(i+1)*2<sum.at(N)) continue;
    long long tmp=abs((sum.at(N)-sum.at(i))-sum.at(i));
    ans=min(ans,tmp);
  }
  cout << ans << endl;

  return 0;
}
