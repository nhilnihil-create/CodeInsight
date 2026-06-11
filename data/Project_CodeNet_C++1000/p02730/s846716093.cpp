#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  bool Palindrome = true;
  for(int i=0;i<S.size()/2;i++){
    if(S.at(i)!=S.at(S.size()-1-i)) Palindrome = false;
//    cout << S.at(i) << " :0 " << S.at(S.size()-1-i) << endl;
  }
  for(int i=0;i<S.size()/2/2;i++){
//    cout << i << " : " << S.size()/2-1-i << " : " << S.size()-1-i << " : " << (S.size()+1)/2+i << endl;
    if(S.at(i)!=S.at(S.size()/2-1-i)) Palindrome = false;
    if(S.at(S.size()-1-i)!=S.at((S.size()+1)/2+i)) Palindrome = false;    
//    cout << S.at(i) << " :1 " << S.at(S.size()/2-1-i) << endl;
//    cout << S.at(S.size()-1-i) << " :2 " << S.at((S.size()+1)/2+i) << endl;
  }
  if(Palindrome) cout << "Yes" << endl;
  else cout << "No" << endl;
}
  