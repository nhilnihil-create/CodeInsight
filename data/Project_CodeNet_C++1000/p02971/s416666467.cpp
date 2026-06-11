#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> a,s;
  for(int i=0;i<n;i++){
    int p;
    cin>>p;
    a.push_back(make_pair(p,i));
    s.push_back(make_pair(p,i));
  }
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  int ans_first=s[0].first;
  int ans_first_index=s[0].second;
  int ans_second=s[1].first;
  int ans_second_index=s[1].second;
  for(int i=0;i<n;i++){
    int a_index=a[i].second;
    if(a_index==ans_first_index){
      cout<<ans_second<<endl;
    }else{
      cout<<ans_first<<endl;
    }
  }
  return 0;
}