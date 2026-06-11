#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>edge;
int main(){
    int n;cin>>n;
    if((1<<int(ceil(log2(n))))==n)
        return puts("No"),0;
    edge.emplace_back(n+1,n+2);
    edge.emplace_back(n+2,n+3);
    edge.emplace_back(n+3,1);
    edge.emplace_back(1,2);
    edge.emplace_back(2,3);
    for(int a=4,b=5;b<=n;a+=2,b+=2){
        edge.emplace_back(a,b);
        edge.emplace_back(a+n,b+n);
        edge.emplace_back(a,1);
        edge.emplace_back(b+n,1);
    }
    if(n%2==0)
        for(int a=2;;a++){
            int b=(n+1)^a;
            if(2<=a&&a<n&&2<=b&&b<n){
                edge.emplace_back(n,a&1?a+n:a);
                edge.emplace_back(2*n,b&1?b+n:b);
                break;
            }
        }
    puts("Yes");
    for(auto i:edge)
        cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}