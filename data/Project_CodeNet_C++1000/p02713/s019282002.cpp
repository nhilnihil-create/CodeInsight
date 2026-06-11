#include<bits/stdc++.h>
using namespace std;
int gcd(int p, int q){
 while(q != 0){
 int r = p % q;
 p = q;
 q = r;
 }
 return p;
 }
int main ()
{
    int i,j,k,n,c=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                c=c+gcd(gcd(i,j),k);
            }
        }
    }
    cout<<c<<endl;
    return 0;
}