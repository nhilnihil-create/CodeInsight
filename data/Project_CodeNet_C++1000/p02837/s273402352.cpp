#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,x,y;
    cin>>n;
    std::multimap<int, pair<int,int>> map;
    for (int i=0;i<n;i++) {
        cin>>a;
        for (int j=0;j<a;j++) {
            cin>>x>>y;
            map.emplace(i+1,make_pair(x,y));
        }
    }
    int count=0,ans=0;
    for (int bit=0;bit<(1<<n);bit++) {
        count=0;
        std::deque<int> honest(n+1,0);
        int flag=0;
        for (int i=0;i<n;i++) {
            if (bit&(1<<i)) {
                honest[i+1]=1;
            }
        }
        for (int k=0;k<n+1;k++) {
            if (honest[k]==1) {
                auto p=map.equal_range(k);
                for (auto itr=p.first;itr!=p.second;itr++) {
                    int X=itr->second.first;
                    int Y=itr->second.second;
                    if (Y==1) {
                        if (honest[X]!=1) {
                            flag=1;
                            break;
                        }
                    } else if (Y==0) {
                        if (honest[X]==1) {
                            flag=1;
                            break;
                        }
                    }
                }
                if (flag==1) {
                    break;
                }
            }
        }
        if (flag==0) {
            for (int l=0;l<n+1;l++) {
                if (honest[l]==1) {
                    count++;
                }
            }
            ans=max(ans,count);
        }
    }
    cout<<ans<<endl;
}
