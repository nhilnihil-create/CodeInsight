#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  vector<int>left(N,0);
  vector<int>right(N,0);
  for(int i=1;i<N;i++)left[i]=max(left[i-1],A[i-1]);
  for(int i=N-1;i>=1;i--)right[i-1]=max(right[i],A[i]);
  for(int i=0;i<N;i++)cout<<max(left[i],right[i])<<endl;
}