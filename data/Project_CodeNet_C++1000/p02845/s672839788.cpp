#include <bits/stdc++.h>
using namespace std;

const int MOD=(int)1e9+7;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++)  cin >> A.at(i);

  long long ans=1;
  vector<int> cnt(3,0);
  for(int i=0;i<N;i++){
    int count=0;
    for(int j=0;j<3;j++){
      if(cnt.at(j)==A.at(i))  count++;
    }
    ans*=count;
    ans%=MOD;
    for(int j=0;j<3;j++){
      if(cnt.at(j)==A.at(i)){
        cnt.at(j)++;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
