#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll a[N], step[N];
int main() {
    ll n, k;
    scanf("%lld%lld",&n,&k);
    for(int i = 1; i <= n; ++i)
        scanf("%lld",&a[i]), step[i] = -1;
    ll t = 1, s = 0, r;

    while(1) {
        //printf("t = %lld s = %lld\n",t,s);
        if(step[t] != -1) {
            r = step[t] + (k-step[t])%(s-step[t]);
            break;
        } else step[t] = s, s++, t = a[t]; 
    }
    
    if(k < s) {
        for(int i = 1; i <= n; ++i)
            if(step[i] == k) {
                printf("%d\n",i);
                break;
            }
    } else {
        for(int i = 1; i <= n; ++i) 
            if(step[i] == r) {
                printf("%d\n",i);
                break;
            }
    }
return 0;
}