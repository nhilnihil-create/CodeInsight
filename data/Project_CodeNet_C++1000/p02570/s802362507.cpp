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
    int d,t,s;
    scanf("%d%d%d",&d,&t,&s);
    if(t*s>=d){
        printf("Yes\n");
    }
    else printf("No\n");
    return 0;
}
