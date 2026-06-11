#include<iostream>
#include<string>

using namespace std;

int main(void){
  string S;
  int cnt = 0,ans = 0;

  cin >> S;

  for(char s : S){
    if(s == 'R') cnt++;

    else cnt = 0;

    ans = max(cnt,ans);
  }

  cout << ans << endl;

  return 0;
}
