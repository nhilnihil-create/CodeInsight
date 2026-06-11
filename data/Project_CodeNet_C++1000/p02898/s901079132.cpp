
#include<bits/stdc++.h>
using namespace std;




int main()
{


     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int t,k;

    cin>>t>>k;
   int count=0;
   for(int i=0;i<t;i++)
   {
    int first;
    cin>>first;
    if(first>=k)
      count++;
   }
   cout<<count<<endl;
    return 0;
    
}