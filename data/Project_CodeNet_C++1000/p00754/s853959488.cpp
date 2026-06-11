#include <iostream>
#include <algorithm>
using namespace std;
bool f(string s){
  int n=s.length();
  if(n==0) return true;
  if(n%2) return false;
  char c = s[0];
  if(c==')'||c==']') return false;
  char d = (c=='(')?')':']';
  int lv=1;
  int l = -1;
  for(int i=1;i<n;++i){
    if(s[i]==d) --lv;
    if(s[i]==c) ++lv;
    if(!lv){
      l = i;
      break;
    }
  }
  if(l==-1) return false;
  return f(s.substr(1,l-1))&&f(s.substr(l+1,n-l-1));
}

int main(){
  string s;
  while(getline(cin,s),s!="."){
    int t1=0,t2=0;
    int n = s.length();
    string t="";
    for(int i=0;i<n;++i){
      if(s[i]=='(' ||
	 s[i]==')' ||
	 s[i]=='[' ||
	 s[i]==']') t+=s[i];
    }
    if(f(t)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
  