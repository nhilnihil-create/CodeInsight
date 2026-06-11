#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  
  int a[n+1]={0};
  
  for(int i=1;i<=n;i++)
  {
    int q;
    cin>>q;
    a[q]=i;
  }
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
  cout<<"\n";
  return 0;
}