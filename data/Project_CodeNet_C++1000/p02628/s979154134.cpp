#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    IOS;
   // freopen("inputfile.txt","r",stdin);
   int n,k;cin>>n>>k;
   int ar[n];
   for(int i=0;i<n;i++)cin>>ar[i];
   int sum = 0;
   sort(ar,ar+n);
   int c = 0 ;
   while(k--)
   {
       sum+=ar[c];
       c++;
   }
   cout<<sum<<endl;
    return 0;
}

