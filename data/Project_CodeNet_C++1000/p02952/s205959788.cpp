#include<bits/stdc++.h>
using namespace std;
int main()
{
   long int n,i,count=0;
   cin>>n;
    string s;
    for(i=1;i<=n;i++)
    {
        s=to_string(i);
        long int l=s.size();
        if(l%2!=0)
        {
            count++;
        }
    }
   cout<<count;
}
