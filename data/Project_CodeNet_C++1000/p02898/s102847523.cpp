#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int k;
  cin>>k;
  int heights[n];
  for(int i=0;i<n;i++)
  {
    cin>>heights[i];
  }
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(heights[i]>=k)
    {
      count++;
    }
  }
  cout<<count;
  
  
 return 0; 
}