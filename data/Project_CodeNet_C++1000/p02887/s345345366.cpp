#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  string s; cin >> s;
  char moji = s.at(0);
  int cnt = 0;
  int ans = n;
  for(int i = 1; i < n; i++){
   // printf("i:%d s.at(i):%c\n",i,s.at(i));
    if(s.at(i) != moji){
      moji = s.at(i);
      ans -= cnt;
      cnt = 0;
      //cout << "ans "<< ans << endl;
    }
    else cnt++;
  }
  cout << ans - cnt;
}