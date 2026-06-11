#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int Q;
  cin>>S>>Q;
  
  bool jun=true;
  vector<char> migi;
  vector<char> hidari;
  for(int i=0;i<Q;i++){
    int a;
    cin>>a;
    if(a==1){
      if(jun) jun=false;
      else jun=true;
    }
    else{
      int b;
      char c;
      cin>>b>>c;
      if(b==1){
        if(jun) hidari.push_back(c);
        else migi.push_back(c);
      }
      else{
        if(jun) migi.push_back(c);
        else hidari.push_back(c);
      }
    }
  }
  if(jun){
    for(int i=hidari.size()-1;i>=0;i--){
      cout<<hidari.at(i);
    }
    cout<<S;
    for(int i=0;i<migi.size();i++){
      cout<<migi.at(i);
    }
    cout<<endl;
  }
  else{
    for(int i=migi.size()-1;i>=0;i--){
      cout<<migi.at(i);
    }
    reverse(S.begin(),S.end());
    cout<<S;
    for(int i=0;i<hidari.size();i++){
      cout<<hidari.at(i);
    }
    cout<<endl;
  }
}