#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  string t;
  cin>>s;
  cin>>t;
  vector<vector<int>>v(26);
  for(int i=0;i<s.size();i++){
    int c=s.at(i)-'a';
    v[c].push_back(i);
  }
  for(int i=0;i<s.size();i++){
    int c=s.at(i)-'a';
    v[c].push_back(i+s.size());
  }  
  long long ans=0;
  long long cur=0;
  for(int i=0;i<t.size();i++){
    int c=t.at(i)-'a';
    
    //対象文字なし
    if(v[c].size()==0){
      cout<<-1<<endl;
      return 0;
    }  
    
    //cur以上の要素の内，一番左側の要素の位置をイテレータで返す
    //cout<<"#"<<cur<<endl;
    cur=*lower_bound(v[c].begin(),v[c].end(),cur)+1;
    //cout<<"$"<<cur<<endl;
    if(cur>=s.size()){
      cur-=s.size();
      ans+=s.size();
    }
  }
  cout<<ans+cur<<endl;
  return 0;
}
