#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i], a[i]--;

    long long now = 0;

    if(k <= n){
        for(long long i = 0; i < k; i++){
            now = a[now];
        }
        printf("%lld\n", now+1);
    }
    else{
        vector<bool> visit(n, false);
        visit[now] = true;
        long long start;
        long long dist;
        for(long long i = 1; i <= n; i++){
            now = a[now];
            if(visit[now] == true){
                dist = i;
                start = now;
                break;
            }
            visit[now] = true;
        }

        now = start;
        vector<long long> v;
        v.push_back(now);
        for(long long i = 1; i <= n; i++){
            now = a[now];
            if(now == start){
                break;
            }
            v.push_back(now);
        }

        long long ans = v[(k-dist)%v.size()];
        printf("%lld\n", ans+1);
    }
    return 0;
}