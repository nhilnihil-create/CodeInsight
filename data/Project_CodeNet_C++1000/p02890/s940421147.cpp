#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[300000];
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    static int cnt[300001], ccnt[300001];
    for(int i=0;i<n;++i) ++cnt[a[i]];
    for(int i=0;i<=n;++i) ++ccnt[cnt[i]];

    int64_t sum[300002] = {0}, xsum[300002] = {0};
    for(int i=1;i<=n;++i){
        sum[i] = sum[i-1] + ccnt[i];
        xsum[i]= xsum[i-1]+ (int64_t)(i)*ccnt[i];
    }
    auto len = [&](int x){
        return (xsum[x-1] + x*(sum[n]-sum[x-1])) / x;
    };

    for(int k=1;k<=n;++k){
        int ok = 0, ng = n+1;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            if(len(mid) < k) ng = mid;
            else ok = mid;
        }
        cout << ok << endl;
    }

    return 0;
}