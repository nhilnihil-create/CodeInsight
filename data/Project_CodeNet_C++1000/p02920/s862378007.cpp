/*
 *  Author : Jun_SH
 *  Solution for ABC 140 F
 */
#include<bits/stdc++.h>
#define int long long
#define sd(a) scanf("%lld",&a)
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=(1<<18)+10;
multiset<int>a;
main(){
    int n,x;
    sd(n);
    for(int i=1;i<=(1<<n);++i){
        sd(x);
        a.insert(-x);
    }
    vector<int>tmp;
    tmp.emplace_back(*a.begin());
    a.erase(a.begin());
    for(int i=0;i<n;++i){
        vector<int>contain;
        for(auto j:tmp){
            auto pos=a.upper_bound(j);
            if(pos==a.end()){
                puts("No");
                return 0;
            }
            a.erase(pos);
            int num=*pos;
            contain.emplace_back(num);
        }
        for(auto j:contain){
            tmp.emplace_back(j);
        }
        sort(tmp.begin(),tmp.end());
    }
    puts("Yes");
}
