#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(long long i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	string s;
  cin >> s;
  int sl = s.length();
  int sw = 0;
  froop1(0,sl / 2){
    if(s[i] != s[sl - i - 1]){
      cout << "No" << endl;
      return 0;
    }
  }
  string s1 = s.substr(0,(sl - 1) / 2);
  int sl1 = s1.length();
  string s2 = s.substr((sl + 3) / 2 - 1,sl - (sl + 3) / 2 + 1);
    int sl2 = s2.length();
  froop1(0,sl1 / 2){
   if(s1[i] != s1[sl1 - 1 - i]){
cout << "No" << endl;
     return 0;
   }
  }
  
  froop1(0,sl2 - 1){
   if(s2[i] != s2[sl2 - 1 - i]){
cout << "No" << endl;
     return 0;
   }
  }
  cout << "Yes" << endl;
 }