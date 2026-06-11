#include <bits/stdc++.h>
using namespace std;
long long go[500000];
bool been[500000];
vector<int> roop;
#define per(k,x,y) for(long long k=x;k<=y;k++)
int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    per(i,1,n)
        scanf("%lld",&go[i]);
    long long at=1,c=0;
    while(!been[at]&&k){
        been[at]=1;
        at=go[at];
        k--;
    }
    if(!k)
        printf("%lld",at);
    else {
        long long w = go[at];
        long long cnt = 1;
        roop.push_back(at);
        while (w != at) {
            cnt++;
            roop.push_back(w);
            w = go[w];
        }        
        printf("%lld\n",roop[(k)%cnt]);
    }

}//
// 6 1
//6 5 2 5 3 2