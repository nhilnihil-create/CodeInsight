#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    if(y==0)
        return x;
    return gcd(y, x%y);
}
int main()
{
    int a,b,c=0,i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                c=c+gcd(gcd(i,j),k);
            }
        }
    }
    cout<<c<<endl;

}
