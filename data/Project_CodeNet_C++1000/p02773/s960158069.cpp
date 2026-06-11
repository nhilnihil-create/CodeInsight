#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  vector<string> s(N);
  for(int i=0; i<N; i++) cin>>s[i];
  
  sort(s.begin(), s.end());
  
  int m=1,maxs=0;
  string t;
  t=s[0];
  
  for(int i=0; i<N-1; i++){
    if(t==s[i+1]){
      m++;
    }else{
      t=s[i+1];
      m=1;
    }
    maxs = max(maxs,m);
  }
//  cerr << maxs << endl;
  
  int ct=0;
  t=s[0];
  for(int i=0; i<N; i++){
    if(t==s[i]){
      ct++;
    }else{
      t=s[i];
      ct=1;
    }
    if(ct==maxs){
      cout << s[i] << endl;
    }else if(maxs==1){
      cout << s[i] << endl;
    }
  }
  
}


          

  
     

        
          
  
          

  