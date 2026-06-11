#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string alpha="abcdefghijklmn";

void dfs(string s,int a){
  if(s.size()==n){
    cout<<s<<endl;
    return;
  }
  else if(s==""){
    string p="a";
    dfs(p,1);
  }
  else{
    string p;
    for(int i=0;i<=a;i++){
      p=s+alpha[i];
      dfs(p,max(a,i+1));
      p=s;
    }
  }
}

int main(){
  cin>>n;
  dfs("",0);
}