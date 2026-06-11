#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>pos[21];
ll inp[100];
map<ll,ll>mp;
vector<ll>triangle;
vector<ll>::iterator upper1, upper2;
int main()
{
  ll i,j,k,l,t,n,x=0,y=0,p,q,z=0;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>p;
    triangle.push_back(p);
    mp[p]++;	
  }
  sort(triangle.begin(),triangle.end());
  for(i=0;i<n;i++)
  {
   z=0;	
    for(j=i+1;j<n;j++)
    {
      p=triangle[i]+triangle[j];
      q=upper_bound(triangle.begin()+j+1,triangle.end(),p)-triangle.begin();
      k=binary_search(triangle.begin(),triangle.end(),p);
      if(k==1)
      {
         z=z+mp[p];	
      }
       
     // x=x+max(y,q-j);
     //cout<<p<<" "<<q-j-1<<'\n';	
     x=x+max(y,q-j-1);
    }
    x=x-z;	
    //cout<<x<<'\n';
  }
  cout<<x;
     
     
     	
  	
}