#include <bits/stdc++.h>
using namespace std;
//解説AC　難しい
int main() {
  int n; cin >>n;
  vector<long long>a(n+1);
  map<long long ,long long>mp;
  for(int i=0;i<n;i++){
    cin>>a[i];
    mp[a[i]]++;
  }
  if(mp.size()==1){
    if(a[0]==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
  }else if(mp.size()==2){
    long long atai=0;
    long long kazu=0;
    auto begin=mp.begin(),end=mp.end();
    for(auto iter=begin;iter!=end;iter++){
      atai=iter->first;
      kazu=iter->second;
      if(atai==0&&kazu*3==n){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
    cout<<"No"<<endl;
    return 0;
  }else if(mp.size()==3){
    long long atai=0;
    long long kazu=0;
    vector<long long>b(3,0);
    int count =0;
    auto begin=mp.begin(),end=mp.end();
    for(auto iter=begin;iter!=end;iter++){
      atai=iter->first;
      kazu=iter->second;
      b[count]=atai;
      count++;
      if(kazu*3!=n){
        cout<<"No"<<endl;
        return 0;
      }
    }
    if((b[0]^b[1]^b[2])==0){
      cout<<"Yes"<<endl;
      return 0;
    }else{
      cout<<"No"<<endl;
      return 0;
    }
  }else{
    cout<<"No"<<endl;
    return 0;
  }
}