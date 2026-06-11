#include<iostream>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;

  int H[n];
  for(int i=0;i<n;i++) cin>>H[i];
  int h[n];
  for(int i=0;i<n;i++)h[i]=1;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;

    if (H[a-1]>=H[b-1]) h[b-1]=0;
    if (H[b-1]>=H[a-1]) h[a-1]=0;
  }

  int counter=0;
  for(int i=0;i<n;i++){
    if (h[i]==1) counter++;
  }

  cout<<counter<<endl;
}