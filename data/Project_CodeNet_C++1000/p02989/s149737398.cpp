#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, a;
  cin>>N;
  vector<int> dfc(100010,0);
  for(int i=0; i<N; i++){
    cin>>a;
    dfc.at(a)++;
  }
  int ans=0;
  int sum=0;
  for(int i=0; i<100000; i++){
    sum+=dfc.at(i);
    if(sum==N/2){
      ans++;
    }
    else if(sum>N/2+1){
      break;
    }
  }
  cout<<ans<<endl;
  
}
  