#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int N;
  cin >> N;
  
  vector<string>s(N);
  vector<int>t(N);
  
  for(int i=0;i<N;i++){
    cin >> s[i] >> t[i];
  }
  
  string m;
  cin >> m;
  
  int p;
  for(int i=0;i<N;i++){
    if(s[i] == m) p = i;
  }
  
  int ans = 0;
  for(int i=p+1;i<N;i++){
    ans += t[i];
  }
  
  cout << ans << endl;
  
  return 0;
}
