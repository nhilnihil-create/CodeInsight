#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e6+5;
int flag[maxn];

signed main()
{
    ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      
    int num;
    cin>>num;
    int index=(7%num);
    int count=1;


    if(!(num%2))
    {
      cout<<"-1"<<endl;
    }
    else
    {

      //77%13
     
    while(index!=0 && flag[index]==0)
    {

      flag[index]=1;
      int temp=index;
      index=((temp*10)%num+7%num)%num;
      //cout<<index<<endl;
      count++;

    }

    if(index!=0 && flag[index]==1)cout<<"-1"<<endl;
    else
      cout<<count<<endl;
    }
   return 0;

   
}