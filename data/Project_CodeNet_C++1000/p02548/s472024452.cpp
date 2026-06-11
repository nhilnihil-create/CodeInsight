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
const int maxn=2500010;//maxn*maxs
const int maxs=1e8+10;
 
char s[maxn];
int main()
{
        int n;
        cin>>n;
        ll sum=0;
        for(int i=1;i<n;i++)
        {
            sum+=(n-1)/i;
        }
        cout<<sum<<endl;
    system("pause");
    return 0;
}
	

