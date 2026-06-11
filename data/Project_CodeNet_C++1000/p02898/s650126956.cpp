#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,k,c=0;
    cin>>n>>k;
    while(n--)
    {
      cin>>i;
      if(i>=k) c++;
    }
 cout<<c<<endl;

return 0;
}
