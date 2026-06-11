#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string,int> name;
  string s;
  vector<string> new_s;
  rep(i,n){
    cin >> s;
    if(name[s]==0)new_s.push_back(s);
    name[s]++;
  }

  int max=0;
  rep(i,new_s.size()){
    if(name[new_s[i]]>max)max=name[new_s[i]];
  }
  vector<string> max_s;
  rep(i,new_s.size()){
    if(name[new_s[i]]==max)max_s.push_back(new_s[i]);
  }

  sort(max_s.begin(),max_s.end());
  rep(i,max_s.size()){
    cout << max_s[i] << endl;
  }
}