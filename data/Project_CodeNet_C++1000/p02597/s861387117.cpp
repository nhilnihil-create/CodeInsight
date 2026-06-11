#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e6+5;
int flag[maxn];

signed main()
{
    ios_base::sync_with_stdio(false);
      cin.tie(NULL);
    
    int count;
    cin>>count;
    string nish;
    cin>>nish;
    vector<int>all[2];
    for(int i=0;i<count;i++)
    {
      if(nish[i]=='W')
        all[0].push_back(i);
      else
        all[1].push_back(i);
    }

    reverse(all[1].begin(),all[1].end());
    int siz=all[0].size();
    int siz1=all[1].size();
    int i=0,j=0;
    int count1=0;
    while(i<siz  && j<siz1 )
    {
       if(all[0][i]<all[1][j])
       {
          count1++;
          i++;
          j++;
       }
       else
       {
        break;
       }
    }

    cout<<count1<<endl;

   return 0;

   
}