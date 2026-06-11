#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k; cin >> n >> k;
    int p[n+1], c[n+1];

    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> c[i];

    int ans  = -INF;

    for(int i=1;i<=n;i++){
        int start = p[i];
        vector<int> v;

        while(true){
            v.push_back(c[start]);
            start = p[start];
            if(start == p[i]) break;
        }

        int times = k/v.size();
        int extra = k%v.size();

        int sum = 0;

        for(int j=0;j<v.size();j++){
            sum += v[j];
        }

        int temp = 0;
        if(times == 0){
            for(int j=0;j<extra;j++){
                temp += v[j];
                ans = max(ans, temp);
            }
            continue;
        }

        temp = (times - 1LL)*sum;
        if(sum < 0) temp = 0;
        if(times >= 2){
            ans = max(ans, temp);
        }

        for(int j=0;j<v.size();j++){
            temp += v[j];
            ans = max(ans, temp);
        }

        for(int j=0;j<extra;j++){
            temp += v[j];
            ans = max(ans, temp);
        }

    }

    cout << ans << "\n";




}
