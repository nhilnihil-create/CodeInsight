#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<stdlib.h>
 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
 
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e6+6;
const int mod=1e9+7;
ll a[maxn],b[maxn];
 
int main()
{
    cin.tie(0);std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=x+y;
        b[i]=x-y;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    cout<<max(a[n]-a[1],b[n]-b[1])<<endl;
	system("pause");
    return 0;
}