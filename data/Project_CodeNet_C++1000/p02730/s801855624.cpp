#include<bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  vector<char> vec1(s.size()),vec2(s.size());//全体の回文
  for(int i=0;i<s.size();i++){
    vec1[i]=s[i];
    vec2[i]=s[i];
  }
  reverse(vec1.begin(),vec1.end());
  bool a=true;
  for(int i=0;i<s.size();i++){
    if(vec1[i]!=vec2[i]){
      a=false;
      break;
    }
  }
  if(!a){
    cout<<"No"<<endl;
    return 0;
  }
  
  int half=(s.size()-1)/2;
  vector<char> vec3(half),vec4(half);//半分までの回文
  for(int i=0;i<half;i++){
    vec3[i]=vec2[i];
    vec4[i]=vec3[i];
  }
  reverse(vec3.begin(),vec3.end());
  for(int i=0;i<half;i++){
    if(vec3[i]!=vec4[i]){
      a=false;
      break;
    }
  }
  if(!a)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}