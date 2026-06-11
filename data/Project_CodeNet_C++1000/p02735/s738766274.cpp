#include<bits/stdc++.h>
using namespace std;
int main()
{
  int h,w;
  cin>>h>>w;
  vector<vector<char> >a(h);
  for(int i=0;i<h;i++)
  {
    a[i].resize(w);
    for(int j=0;j<w;j++)
    {
		cin>>a[i][j];
    }
  }
  vector<vector<int> >ans(h);
  for(int i=0;i<h;i++)
  {
    ans[i].resize(w);
    for(int j=0;j<w;j++)
    {
      if(i!=0 && j!=0)ans[i][j]=min(ans[i-1][j],ans[i][j-1]);
      else if(i==0 && j!=0)ans[i][j]=ans[i][j-1];
      else if(i!=0 && j==0)ans[i][j]=ans[i-1][j];
      
      if(a[i][j]=='#')
      {      
        if(i!=0 && j!=0)
        {
          //if(ans[i][j]==ans[i-1][j] && ans[i][j]==ans[i][j-1])
          if(ans[i][j]==ans[i-1][j] && a[i-1][j]=='#')continue;
          else if(ans[i][j]==ans[i][j-1] && a[i][j-1]=='#')continue;
          else 
          {
            ans[i][j]++;
          }
            
        }
        else if(i==0 && j!=0 && a[i][j-1]=='.')ans[i][j]++;
        else if(i!=0 && j==0 && a[i-1][j]=='.')ans[i][j]++;
        if(i==0 && j==0)ans[i][j]++;
      }
    }
  }
  cout<<ans[h-1][w-1]<<endl;
 /* for(int i=0;i<h;i++)
  {
    //a[i].resize(w);
    for(int j=0;j<w;j++)
    {
		cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }*/
  
  return 0;
}
   