#include<iostream>
using namespace std;

bool backet(char a){
  if(a=='(')return true;
  if(a==')')return true;
  if(a=='[')return true;
  if(a==']')return true;
  if(a=='{')return true;
  if(a=='}')return true;
  return false;
}

bool check(char a,char b){
  if(a=='(' && b==')')return true;
  if(a=='[' && b==']')return true;
  if(a=='{' && b=='}')return true;
  return false;
}

int main(){
  string s;
  int ans = 0;
  //int n;

  //cin >> n;
  //for(int i=0;i<n;i++){
  while(getline(cin, s)){
    if(s==".")break;
    for(int j=0;j<(int)s.size();j++)
      if(!backet(s[j])){
	s.erase(s.begin()+j);
	j--;
      }

    bool f = true;
    while(f){
      f = false;
      for(int j=0;j<(int)s.size()-1;j++)
	if(check(s[j],s[j+1])){
	  s.erase(s.begin()+j);
	  s.erase(s.begin()+j);
	  j--;
	  f = true;
	}
    }
    if(s.size())cout << "no\n";
    else cout << "yes\n";
    //if(s.size()==0)ans++;
  }
  //cout << ans << endl;
}