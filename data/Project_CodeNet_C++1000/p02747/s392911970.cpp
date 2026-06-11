#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const ld Pi=acos(-1);
int main(){
  string str;
  cin>>str;
  if(str.size()%2==0){
    for(ll i=0;i<((ll)str.size()/2);i++){  
      if(str.at(2*i)!='h' || str.at(2*i+1)!='i'){break;}
      if(i==((ll)str.size()/2-1)){cout<<"Yes"<<endl;return 0;}
    }
  }
  cout<<"No"<<endl;
}