#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    int ans = 0;
    char str[55];
    scanf("%d",&n);
    scanf(" %s",str);
    for(int i=0; i<n; ++i){
        if(str[i]=='A' && i<n-2){
            if(str[i+1]=='B')
                if(str[i+2]=='C')
                    ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

