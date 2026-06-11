#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,sum=0,low=0,high,answer=0,x;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
    sum+=a[i];
  }
  
  for(int i=0;i<=N;i++){
    low+=a[i];
    high=sum-low;
    x=abs(high-low);
    if(i==0) answer=x;
    else if(x<answer) answer=x;
  }
  cout<<answer<<endl;
}
    
  