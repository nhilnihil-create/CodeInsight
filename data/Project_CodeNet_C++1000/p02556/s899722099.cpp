#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int P=139;
const int mod=149;
const int maxn=1e6+5;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int minn=0xc0c0c0c0;
int a[maxn],b[maxn];
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        int x,y;
        cin>>x>>y;
        a[i]=x+y;
        b[i]=x-y;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    cout<<max(a[n]-a[1],b[n]-b[1])<<endl;
    return 0;
}