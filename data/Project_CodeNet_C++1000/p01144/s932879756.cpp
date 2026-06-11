#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main() {
    int N,M;
    while(scanf("%d %d",&N,&M),N) {
        priority_queue<P> Q;
        for(int i=0;i<N;i++) {
            int d,p;
            scanf("%d %d",&d,&p);
            Q.push(P(p,d));
        }
        int sum=0;
        while(!Q.empty()) {
            P p=Q.top();Q.pop();
            int d=min(p.second,M);
            M-=d;
            p.second-=d;
            sum+=p.second*p.first;
        }
        printf("%d\n",sum);
    }
}