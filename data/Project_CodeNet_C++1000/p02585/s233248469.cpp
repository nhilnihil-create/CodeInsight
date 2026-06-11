#include <iostream>
#include <vector>
using namespace std;

long long n, K, p[5005], c[5005], ans = -1e9;
vector <long long> v;

int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++){
        int now = i;
        v.clear();
        v.push_back(c[now]);
        long long tot = c[now];
        now = p[now];
        while (now != i){
            v.push_back(c[now]);
            tot += c[now];
            now = p[now];
        }
        long long k = K;
        if (tot > 0){
            long long tmp = k/v.size();
            if (tmp) tmp--;
            tot *= tmp;
            k -= tmp*v.size();
            ans = max(ans, tot);
        }
        else{
            tot = 0;
            k = min(k, (long long)v.size());
        }
        for (int j = 0; j < k; j++){
            tot += v[j%v.size()];
            ans = max(ans, tot);
        }
    }
    cout << ans << "\n";
}
