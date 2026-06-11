#include<bits/stdc++.h>
#define ll long long
#define P pair<int,int>
using namespace std;
const int maxn = 3e5 + 50;
int a[maxn];
ll sum[maxn];
ll pre[maxn];
int n;
vector<int> v;
void init(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x; scanf("%d", &x); a[x]++;
    }
    for(int i = 1; i <= n; ++i) pre[a[i]]++;
    for(int i = 1; i <= n; ++i) sum[i] = sum[i-1] + i*pre[i], pre[i] += pre[i-1];
}
bool check(int k, int lim){
    k -= (pre[n] - pre[lim-1]);
    if(k <= 0) return true;
    return sum[lim-1] >= (ll)k*lim;
}
void sol(){
    printf("%d\n", n);
    int p = 0;
    for(int k = 2; k <= n; ++k){
        if(k > pre[n]){
            printf("0\n"); continue;
        }
        int l = 0, r = n;
        int ans;
        while(l <= r){
            int mid = (l+r)>>1;
            if(check(k,mid)) ans = mid, l = mid + 1;
            else r = mid-1;
        }
        printf("%d\n", ans);
    }
}
int main()
{
	init(); sol();
}
