#include<bits/stdc++.h>
using namespace std;

int main(){
  int q,t,b;
  cin >> q >> t;
  map<int,bool>deta;
  map<int,int>pena;
  string s;
  int ac=0,pe=0;
  for(int i=0;i<t;i++){
    cin >> b >> s;
    if(!deta[b]){
      if(s=="WA"){
        deta[b]=false;
        pena[b]++;
      }else{
        deta[b]=true;
        ac++;
        pe+=pena[b];
      }
    }
  }
  cout << ac << " " << pe << endl;
  return 0;
}