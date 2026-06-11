#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(r,n,p) for(r::iterator it=p.begin();it!=p.end();++it)
#define MAX2N 250000
char p[250000]={};
using namespace std;
int main()
{
    memset(p,0,sizeof(p));
    p[0] = 1;
    p[1] = 1;
    for(int i=2;i<MAX2N;i++)
    {
        if(p[i] == 0)
        for(int j=2*i;j<MAX2N;j+=i)
        {
            p[j] = 1;
        }

    }
    int n;
    while(cin >> n)
    {
        if(n==0)break;
        int ans = 0;
        for(int i=n+1;i<=2*n;i++)
        {
            if(p[i]==0) ans++;

        }
        cout << ans << endl;
    }
    
    return 0;
}