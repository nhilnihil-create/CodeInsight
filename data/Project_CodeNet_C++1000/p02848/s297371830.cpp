 #include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int sl = s.length();
  string ans;
  for(int i = 0; i < sl; i++){
    if(s[i] + n > 90){
      ans += (char)(s[i] + n - 90 + 64);
    }else{
      ans += (char)(s[i] + n);
      
    }
   
  }

  cout <<  ans << endl;
  return 0;
}