#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    long long int a,b;
    std::multimap<long long int, long long int> map;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>a>>b;
        map.emplace(b,a);
        deq.emplace_back(b);
    }
    sort(deq.begin(),deq.end());
    long long int now=0,dead=0,tmp=0;
    for (int i=0;i<n;i++) {
        if (tmp!=deq[i]) {
            auto p=map.equal_range(deq[i]);
            for (auto itr=p.first;itr!=p.second;itr++) {
                now+=itr->second;
                dead=max(dead,deq[i]);
                //cout<<"now="<<now<<" "<<"dead="<<dead<<endl;
                if (now>dead) {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            tmp=deq[i];
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}