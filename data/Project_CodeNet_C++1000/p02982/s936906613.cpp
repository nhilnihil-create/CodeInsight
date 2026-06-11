#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll n,d,arr[20][20];
     cin>>n>>d;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<d;j++)
         {
             cin>>arr[i][j];
         }
     }
     ll cnt=0,sum=0;
     for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             for(int k=0;k<d;k++)
             {
                 ll nk=arr[i][k]-arr[j][k];
                 sum+=(pow(nk,2));
             }
             ll kk=sqrt(sum);
             if(kk*kk==sum)
                cnt++;
             sum=0;
         }
     }
     cout<<cnt<<endl;
}
