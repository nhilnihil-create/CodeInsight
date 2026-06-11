#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,n=1,ans=0;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a==n)
      n++,ans++;
  }
  if(ans==0)
    cout<<-1<<endl;
  else
    cout<<N-ans<<endl;
}