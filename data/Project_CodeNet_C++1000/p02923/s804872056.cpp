#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int H[N];
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  int check = 0;
  int count = 0;
  int ans = 0;
  
  for(int i=0;i<N-1;i++){
    if(H[i]<H[i+1]){
      ans = max(ans,count);
      count = 0;
    }
    else count++;
  }
  cout<<max(ans,count)<<endl;
}
    
    