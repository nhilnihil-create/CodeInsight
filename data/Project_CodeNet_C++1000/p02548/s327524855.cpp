#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int g[N];
int n;
int main()
{
    cin>>n;
    // a*b+c=n -> b=(n-c)/a
    int res=0;
    for(int i=1;i<=n;i++)//枚举A
        for(int j=1;j<=n/i;j++)//枚举B
        {
            int c=n-i*j;
            if(c && i*j+c == n) res++;
        }
    
    cout<<res;
    
 
    
}