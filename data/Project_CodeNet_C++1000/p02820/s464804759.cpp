#include<bits/stdc++.h>
using namespace std;
int r,s,p;


int win(char c){
  if(c=='r') return p;
  else if(c=='s') return r;
  else return s;
}

int main(){
  int n,k,ans=0;
  string t;
  cin>> n >> k >> r >> s >> p >> t;
  for (int i=0; i<k; i++){
    string check;
    bool pre=true;
    for(int j=i; j<t.size(); j+=k){ check.push_back(t[j]); }
    ans+=win(check[0]);
    for(int j=1; j<check.size(); j++){
      if(check[j-1]==check[j] && pre){ pre=false; continue;}
      ans+=win(check[j]);
      pre=true;
    }
  }
  cout<< ans <<endl;
}