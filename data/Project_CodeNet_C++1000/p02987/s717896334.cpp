#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
 
int main(){
  string S;
  cin>>S;
  map<char, int> amap;
  vector<char> arr;
  for(int i=0;i<4;++i){
    if(amap[S[i]]==0) arr.push_back(S[i]);
    amap[S[i]]++;
  }
  bool ok = true;
  if(arr.size()!=2) ok = false;
  else{
    if(amap[arr[0]]!=amap[arr[1]]) ok = false;
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}