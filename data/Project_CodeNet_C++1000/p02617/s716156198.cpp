#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define Int long long




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Int n;
    cin>>n;
    Int cv=(n*(n+1))/2;
  	cv*=n;
  	for(int i = 1;i<=n;i++)
    {
        Int j = (n*(n+1))/2;
      	j-=(i)*(n-i+1);
        cv-=j;
    }
    for(int i = 1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
      	if(x>y)swap(x,y);
        cv-=x*(n-y+1);
    }
  	//assert(cv>=0);
    cout<<cv<<endl;
}
