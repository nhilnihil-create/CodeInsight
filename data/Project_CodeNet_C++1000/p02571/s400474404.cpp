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
    char s1[1005],s2[1005];
    scanf("%s",s1);
    scanf(" %s",s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int ans = 1e8;
    for(int i=0; i+len2<=len1; ++i){
        int t = 0;
        //枚举不相等的个数
        for(int j=0; j<len2; ++j){
            if(s1[i+j]!=s2[j])
                t++;
        }
        ans = min(ans,t);
    }
    printf("%d\n",ans);
    return 0;
}
