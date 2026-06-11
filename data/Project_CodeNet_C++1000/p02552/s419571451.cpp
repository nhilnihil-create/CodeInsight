#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define MAX 100005
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==1)
        cout<<n-1;
    else if(!n)
        cout<<n+1;
    return 0;
}