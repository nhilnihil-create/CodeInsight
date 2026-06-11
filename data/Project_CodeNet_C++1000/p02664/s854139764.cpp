#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='?' && s[i-1]=='P'){
      s[i]='D';
    }else if(s[i]=='?' && s[i-1]=='D' && s[i+1]=='D'){
      s[i]='P';
    }else if(s[i]=='?' && s[i-1]=='D' && s[i+1]=='P'){
      s[i]='D';
    }else if(s[i]=='?' && s[i+1]=='?'){
      s[i]='P';
    }else if(s[i]=='?'){
      s[i]='D';
    }
  }
  for(int i=0;i<s.size();i++){
    cout << s[i] ;
  }
  cout << endl;
}
