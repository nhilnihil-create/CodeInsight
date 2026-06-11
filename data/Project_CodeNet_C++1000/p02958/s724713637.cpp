#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> p(N);
  
  for(int i=0; i<N; i++) cin >> p[i];
  
  int cnt = 0;
  int x, y;
  for(int i=0; i<(N-1); i++){
    if(p[i]>p[i+1]){
      cnt += 1;
      
      if(cnt==1){
        x=i;
      }else if(cnt==2){
        y=i;
      }else if(cnt==3){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  
  if(cnt==0){
    cout << "YES" << endl;
  }else if(cnt==2 && p[x]>p[y] && p[x+1]>p[y+1]){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
  
  return 0;
}