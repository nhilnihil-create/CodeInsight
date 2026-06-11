#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  string s;  cin >> s;

  long ans = 0;

  for(int i=0; i<1000; i++){
    int nowi = i, cnt = 0;
    for(int j=s.size()-1; j>=0; j--){
      if(s[j] == (char)((int)'0'+(nowi%10))){
	if(++cnt > 2){
	  ans++;
	  break;
	}
	nowi /= 10;
      }
    }
  }
  cout << ans << endl;  

  return 0;
}
