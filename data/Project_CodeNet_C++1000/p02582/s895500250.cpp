#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(int a,int b){
  return a<b;//ascending
} 

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


    string s;
    cin>>s;
    int p=0;
    int count=0;
    int max=0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='R'){
        count++;
        if(count>max){
      max=count;
    }
      }
      else if(s[i]=='S'){
        count=0;
        continue;
        
      }
    }
  cout<<max<<endl;

  return 0;
}