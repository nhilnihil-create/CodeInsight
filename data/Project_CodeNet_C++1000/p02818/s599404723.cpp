#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long n,m,k,p,q;
   cin>>n>>m>>k;
   if(n>k) cout<<n-k<<" "<<m<<endl;
   else
   {
            cout<<0<<" ";
            p=k-n;
            q=m-p;
            if(m>p) cout<<q<<endl;
            else cout<<0<<endl;
   }
}

