#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  string s;
  cin>>s;
  int k;
  int rorl[100000];
  for(int i=0;i<s.size();i++){ //Rとの距離
    if(s[i]=='L') rorl[i]=k;
    else k=i;
  }
  for(int i=s.size()-1;i>=0;i--){ //Lとの距離
    if(s[i]=='L') k=i;
    else rorl[i]=k;
  }
  int answer[100000];
  for(int i=0;i<s.size();i++) answer[i]=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='L'){
      if((i-rorl[i])%2==0) answer[rorl[i]]++;
      else answer[rorl[i]+1]++;
    }
    else{
      if((rorl[i]-i)%2==0) answer[rorl[i]]++;
      else answer[rorl[i]-1]++;
    }
  }
  for(int i=0;i<s.size();i++){
    if(i<s.size()-1) cout<<answer[i]<<' ';
    else cout<<answer[i]<<endl;
  }
  
  return 0;
}