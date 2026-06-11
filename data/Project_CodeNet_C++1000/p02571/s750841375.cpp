#include <iostream>
using namespace std;

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
  string s,t;
  int ans;
  
  cin >> s >> t;
  ans = t.size();
  for (int i=0; i<s.size()-t.size()+1; i++){
    int d=t.size();
    for (int j=0; j<t.size(); j++){
      d -= s[i+j]==t[j];
    }
    ans = MIN(ans, d);
  }
  cout << ans << endl;
  
  return 0;
}