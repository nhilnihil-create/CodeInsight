#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,maxt=-1;
  cin >> n ;
  map<string,int> me;
  for(int i=0;i<n;i++){
    string a;
    cin >> a;
    me[a]+=1;
  }
  for(const auto x :me){
    int v=x.second;
    if(v>maxt)maxt=x.second;
  }
  for(auto it=me.begin();it!=me.end();it++){
    if(it->second == maxt){
      cout << it->first << endl;
    }
  }
}
  
    
