#include <iostream>
#include <bits/stdc++.h>
#include <set>

using namespace std;
int n;
pair<int,int> ps[100005];
bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first > b.first;
}

int main()
{
    set<int> ss;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&ps[i].first);
        ps[i].second = i+1;
    }
    sort(ps,ps+n,cmp);
    ss.insert(ps[0].second);
    int l,r;
    long long ans = 0;
    for(int i=1;i<n;++i)
    {
        auto pos = ss.upper_bound(ps[i].second);
        if(pos!=ss.end()){
            auto pos2 = pos;++pos2;
            if(pos2==ss.end()) r=n+1;
            else r = *pos2;
            if(pos!=ss.begin()){
                pos2 = pos;--pos2;
                l = *pos2;
            }else l=0;
            ans += 1LL*(ps[i].second-l)*(r-*pos)*ps[i].first;
        }
        auto pos3 = pos;

        if(pos!=ss.begin()){
            --pos;
            auto pos2 = pos;
            if(pos2==ss.begin()) l = 0;
            else {
                --pos2;l=*pos2;
            }
            if(pos3==ss.end()) r= n+1;
            else {
                r = *pos3;
            }
            ans += 1LL*(*pos-l)*(r-ps[i].second)*ps[i].first;
        }
        ss.insert(ps[i].second);
        //cout << ps[i].first << " "<<ans << endl;
    }

    printf("%lld\n",ans);
    return 0;
}
