#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 0x3f3f3f3f
int n;
int main()
{
    scanf("%d",&n);
    if(n%2)
    {
        cout<<n/2<<endl;
    }
    else
    {
        cout<<n/2-1<<endl;
    }
}
