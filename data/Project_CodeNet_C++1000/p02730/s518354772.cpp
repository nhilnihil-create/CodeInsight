#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  string S;
  int a = 0;
  int b = 0;
  int c = 0;
  int y = 0;
  int x = 0;
  cin>>S;
  string s = S;
  reverse(s.begin(),s.end());
  if(s == S){
    a = 1;
  }
  y = ((S.size() - 1 / 2) - 1) / 2;
  string d2;
  for(int i = 0;i < y;i++){
    d2.push_back(S[i]);
  }
  string d = d2;
  reverse(d.begin(),d.end());
  if(d == d2){
    b = 1;
  }
  x = (((S.size() + 3) / 2) - 1);
  string s2;
  for(int i = x;i < (S.size());i++){
    s2.push_back(S[i]);
  }
  string s3 = s2;
  reverse(s3.begin(),s3.end());
  if(s3 == s2){
    c = 1;
  }
  if(a == 1 && b == 1 && c == 1){
    cout<<"Yes"<<'\n';
  }else{
    cout<<"No"<<'\n';
  }
}