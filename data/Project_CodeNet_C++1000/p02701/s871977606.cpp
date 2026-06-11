#include<bits/stdc++.h>
using namespace std;


int main(){

  int n;
  cin>>n;
  unordered_map<string,int> umap;

  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    umap[s]++;
  }

  // for( auto i : umap){
  //   cout<<i.first<<" "<<i.second<<"\n";
  // }
   
    cout<<umap.size()<<"\n";


  return 0;
}