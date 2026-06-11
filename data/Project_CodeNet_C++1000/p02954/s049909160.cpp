#include<bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin >> N;
  int b=N.size();
  vector<int> vec(b,0);
  int cnt=0,cnt1=0,cnt2=0;
  
  cnt=0;cnt1=0;cnt2=0;
  for(int i=0;i<b;i++){
    if(N[i]=='R'){
      cnt++;
      if(cnt%2==0){
        cnt1++;
      }
      else{
        cnt2++;
      }
    }
    else{
      cnt=0;
      if(N[i-1]=='R'){
        vec[i]+=cnt1;
        vec[i-1]+=cnt2;
        cnt1=0;
        cnt2=0;
      }
    }
  }
  
  reverse(N.begin(),N.end());
  for(int i=0;i<b;i++){
    if(N[i]=='L'){
      cnt++;
      if(cnt%2==0){
        cnt1++;
      }
      else{
        cnt2++;
      }
    }
    else{
      cnt=0;
      if(N[i-1]=='L'){
        vec[b-i-1]+=cnt1;
        vec[b-i]+=cnt2;
        cnt1=0;
        cnt2=0;
      }
    }
  }
  for(int i=0;i<b;i++){
    cout << vec[i] << ' ';
  }
}


  