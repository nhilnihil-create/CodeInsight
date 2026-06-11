#include<iostream>

using namespace std;
int main (void)
{
  int a[3][3],b[100],n,i,j,k;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      cin>>a[i][j];
    }
  }
  cin>>n;
  for(i=0;i<n;i++){cin>>b[i];}
for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      for(k=0;k<n;k++)
      if(a[i][j]==b[k]){a[i][j]=0;}
    }
  }
  for(i=0;i<3;i++){if(a[i][1]==0&&a[i][2]==0&&a[i][0]==0){cout<<"Yes"<<endl;return 0;}}
  for(i=0;i<3;i++){if(a[1][i]==0&&a[2][i]==0&&a[0][i]==0){cout<<"Yes"<<endl;return 0;}}
  if(a[0][0]==0&&a[1][1]==0&&a[2][2]==0){cout<<"Yes"<<endl;return 0;}
  if(a[0][2]==0&&a[1][1]==0&&a[2][0]==0){cout<<"Yes"<<endl;return 0;}
  cout<<"No"<<endl;return 0;
 
}

