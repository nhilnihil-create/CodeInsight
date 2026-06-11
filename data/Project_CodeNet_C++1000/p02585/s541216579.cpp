#include <bits/stdc++.h>
using namespace std;
long long const MX = 2e5 + 2, MOD = 1e9 + 7;
long long c[MX], p[MX];
int main()
{
    long long t = 1;
//    cin>>t;
    while(t--){
        long long n , k;
        cin>>n>>k;
        long long mx = -1e9 - 1;
        for(long long i = 0; i < n; i++) cin>>p[i],p[i]--;
        for(long long i = 0; i < n; i++){
            cin>>c[i];
            mx = max(mx, c[i]);
        }
        if(mx <= 0) {
            cout<<mx;
            continue;
        }
        mx = -1e15;
        for(long long i = 0; i < n; i++){
            long long cntp = 0, sum = 0, x = i;
            while(true){
                sum += c[p[x]];
                x = p[x];
                cntp++;
                if(x == i) break;
            }
//            long long l = k, ans = 0;
//                ans += max(0ll, sum) * ((long long)k/cntp);
//                l = k % cntp;
//            mx = max(mx, ans);
//            for(long long j = 0; j < cntp; j++){
//                if(j == l) break;
//                ans = ans + c[p[x]];
//                x = p[x];
//                mx = max(mx, ans);
//            }
            long long cnt = 0, path = 0;
            x = i;
            while(true){
                cnt++;
                path += c[x];
                if(cnt > k) break;
                int num = (k - cnt)/cntp;
                long long score = path + max(0ll, sum)*num;
                mx = max(mx, score);
                x = p[x];
                if(x == i) break;
            }
        }
        cout<<mx;
    }
}


