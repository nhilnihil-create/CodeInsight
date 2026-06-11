#include<bits/stdc++.h>
using namespace std;
int  lft[200005], rght[200005];
char str[200005];
bool ok[200005];
int main()
{
    int n, k, c;
    scanf("%d %d %d %s", &n, &k, &c, str+1);
    int prev= 0;
    for(int i=1; i<=n; i++)
    {
        if(str[i]=='x')continue;
        lft[i]= prev++;
        for(int j=i+1; j<=i+c && j<=n; j++)lft[j]= prev;
        i+= c;
    }
    prev= 0;
    for(int i=n; i>0; i--)
    {
        if(str[i]=='x')continue;
        rght[i]= prev++;
        for(int j=i-1; j>=i-c && j>0; j--)rght[j]= prev;
        i-= c;
    }
    for(int i=1; i<=n; i++)
    if(str[i]=='o' && (lft[i]+rght[i])<k)
    printf("%d\n", i);
    return 0;
}
