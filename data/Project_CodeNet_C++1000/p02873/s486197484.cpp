#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int num[500005];
int main(){
  string s;
  cin >> s;

  for(int i=0; i<s.size(); i++){
    if(s[i] == '<'){
      num[i+1] = num[i]+1;
    }
  }

  for(int i=s.size()-1; i>=0; i--){
    if(s[i] == '>'){
      num[i] = max(num[i], num[i+1]+1);
    }
  }

  long long ans = 0;
  for(int i=0; i<=s.size(); i++){
    ans += num[i];
  }

  cout << ans << endl;

  return 0;
}