#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<t;i++)
int num[1<<18];
int main()
{
    int n;scanf("%d",&n);
    rep(i,0,1<<n)scanf("%d",&num[i]);
    sort(num,num+(1<<n),greater<int>());
    priority_queue<int> pq;
    int flag=1;vector<int> tmp;
    tmp.push_back(n);
    rep(i,1,(1<<n))
    {
        if(num[i]!=num[i-1])
        {
            for(int k:tmp)pq.push(k);
            tmp.clear();
        }
        if(pq.empty()){flag=0;break;}
        int x=pq.top();pq.pop();
        if(x!=1)tmp.push_back(x-1),pq.push(x-1);
    }
    if(flag)printf("Yes\n");
    else printf("No\n");
}
