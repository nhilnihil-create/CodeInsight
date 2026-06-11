#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >>N>>M;
  vector<int> a(M);
  vector<string> b(M);
  for(int i=0;i<M;i++){
    cin >> a[i];
    cin >> b[i];
  }
  
  int ans1=0,ans2=0;
  vector<int> c(N,0);
  vector<int> d(N,0);
  for(int i=0;i<M;i++){
    if(b[i]=="WA"){
      if(!(c[a[i]-1])){
        d[a[i]-1]++;
      }
      else{
        continue;
      }
    }
    if(c[a[i]-1]){
      continue;
    }
    if(b[i]=="AC"){
      c[a[i]-1]=1;
      ans1++;
      ans2+=d[a[i]-1];
    }
  }
  cout << ans1 << ' ' << ans2 <<endl;
}

      
    
    
  