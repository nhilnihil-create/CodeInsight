#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for(int i = (s); i < (int)(n); i++)
typedef long long ll;

bool isPalindrome(string s){
  int l=s.size();
  for(int i=0; i<l/2; i++){
    if(s[i]!=s[l-1-i]){
      return false;
    }
  }
  return true;
}

int main(){
  string s, t1, t2;
  cin >> s;
  int n=s.size();
  t1=s.substr(0, (n-1)/2);
  t2=s.substr((n+1)/2, (n-1)/2);
  if(isPalindrome(s)==1&&isPalindrome(t1)==1&&isPalindrome(t2)==1){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}