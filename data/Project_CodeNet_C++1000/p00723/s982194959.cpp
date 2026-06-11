#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
bool isPalindrome(int l,int r,string& s){
  while(l < r){
    if(s[l] != s[r])return false;
  }
  return true;
}
int solve(string& s){
  set<string> strs;
  for(int i = 1,l = s.size();i < l;i++){
    string s1 = s.substr(0,i);
    string s2 = s.substr(i,l-i);
    //cout << s1 <<':' <<  s2 << endl;
    string s1rev = s1;reverse(s1rev.begin(), s1rev.end());
    string s2rev = s2;reverse(s2rev.begin(), s2rev.end());
    //cout << s1rev << ':' <<  s2rev << endl;
    strs.insert(s1    +s2);
    strs.insert(s1    +s2rev);
    strs.insert(s1rev +s2);
    strs.insert(s1rev +s2rev);
    strs.insert(s2    +s1);
    strs.insert(s2    +s1rev);
    strs.insert(s2rev +s1);
    strs.insert(s2rev +s1rev);
  }
  /*for(auto i:strs){
    cout << i << endl;
    }*/
  return strs.size();
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  for(int i = 0;i < n;i++){
    string s;
    getline(cin,s);
    cout << solve(s) << endl;
  }
}