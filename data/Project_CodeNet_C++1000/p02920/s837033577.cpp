#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
int n;
multiset<int>s,s2;
multiset<int>::iterator it,it2;
int tot,st[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=1<<n;i++)
    {
        int x;scanf("%d",&x);s.insert(x);
    }
    it=s.end();
    it--;
    s2.insert(*it);
    s.erase(s.find(*it));
    while(s.size())
    {
        it2=s2.end();it2--;
        while(true)
        {
            it=s.lower_bound(*it2);
            if(it==s.begin()) {printf("No\n");return 0;}
            it--;st[++tot]=*it;s.erase(s.find(*it));
            if(it2==s2.begin()) break;
            it2--;
        }
        for(int i=1;i<=tot;i++) s2.insert(st[i]);tot=0;
    }
    printf("Yes\n");
}
