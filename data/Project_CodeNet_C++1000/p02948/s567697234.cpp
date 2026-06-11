#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m;
pair<int,int> ab[100005];
priority_queue<int> que;

bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d%d",&ab[i].first,&ab[i].second);
    sort(ab,ab+n,cmp);
    int j=0;long long ans = 0;
    for(int i=1;i<=m;++i){
        while(j<n&&ab[j].first<=i){
            que.push(ab[j].second);++j;
        }
        if(!que.empty()){
            ans+=que.top();que.pop();
        }
    }
    printf("%lld\n",ans);
    return 0;
}
