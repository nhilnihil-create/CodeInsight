#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
  string s;
  cin >> s;
  int leng = s.length();
  vector<int> child(leng,0);
  int j = 0,k1 = 0,k2 = 0,sw = 0;
  froop1(0,leng - 1){
    if(s[i] == 'R' && s[i + 1] == 'L'){
      k1 = i;k2 = i + 1;sw = 1;
      child.at(k1) = 1;child.at(k2) = 1;
    }else if(s[i] == 'L' && s[i + 1] == 'R'){
      int l = i; 
      child.at(k1) += (k1 - j) / 2 + (l - k1) / 2;
      child.at(k2) += (k2 - j) / 2 + (l - k2) / 2;
      j = i + 1;
      sw = 0;
    }
  }
  if(s[leng - 2] == 'R' && s[leng - 1] == 'L'){
    child.at(leng - 2) = 1;
    child.at(leng - 1) = 1;
  }
  if(sw == 1){
	  child.at(k1) += (k1 - j) / 2 + (leng - 1 - k1) / 2;
      child.at(k2) += (k2 - j) / 2 + (leng - 1 - k2) / 2;
  }
froop1(0,leng){
cout << child.at(i);
  if(i != leng - 1){
    cout << " ";
  }else{
    cout << endl;
  }
  }
}