#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int ar[1000000]={0};
  int n;
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int temp;
    cin>>temp;
    ++ar[temp];
  }
  for(int i=1;i<=n;i++)
  {
    printf("%d\n",ar[i]);
  }
}