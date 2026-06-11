#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B,M,a,b,x,y,c;
    cin>>A>>B>>M;
    std::deque<int> re;
    deque<int> ra;
    int minA=100001,minB=100001;
    for (int i=0;i<A;i++) {
        cin>>a;
        re.emplace_back(a);
        minA=min(minA,a);
    }
    for (int j=0;j<B;j++) {
        cin>>b;
        ra.emplace_back(b);
        minB=min(minB,b);
    }
    int ans=minA+minB;
    for (int k=0;k<M;k++) {
        cin>>x>>y>>c;
        ans=min(ans,re[x-1]+ra[y-1]-c);
    }
    cout<<ans<<endl;
}
