#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,k;

int main()
{
    scanf("%d %d",&n,&k);
    if (k==1) cout<<0;
    else cout<<n-k;
    return 0;
}
