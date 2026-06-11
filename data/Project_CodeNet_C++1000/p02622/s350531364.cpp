#include <iostream>
using namespace std;
int main(){
  string S;
  string T;
  cin >> S >> T;
  int ans=0;
  int N= S.size();
  for(long long int i=0; i<N ; i++){
    if(S[i]!=T[i]){
      ans+=1;
    }
  }
  cout << ans << endl;
}
