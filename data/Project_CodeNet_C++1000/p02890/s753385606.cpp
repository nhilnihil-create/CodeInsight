#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;

int freq[N], cum[N];

bool tmam(int mid, int i){
    ll ans = freq[mid - 1] / mid + cum[mid];
    return ans >= i;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<int> v;
    for(int i = 1; i <= 3e5; i++){
        if(freq[i]) v.push_back(freq[i]);
    }
    sort(v.begin(), v.end());
    memset(freq, 0, sizeof freq);
    for(int i = 0; i < v.size(); i++){
        int x = v[i];
        freq[x] = freq[x] + x;
    }
    for(int i = 1; i <= 3e5; i++){
        freq[i] += freq[i - 1];
    }
    for(int i = (int) v.size() - 1; i >= 0; i--){
        int x = v[i];
        cum[x]++;
    }
    for(int i = 3e5; i; i--) cum[i] += cum[i + 1];
    // for(int i = 1; i <= n; i++) cout << freq[i] << ' ';
    for(int i = 1; i <= n; i++){
        int low = 1, high = n / i, mid, ans = 0;
        while(high >= low){
            mid = low + high >> 1;
            if(tmam(mid, i)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
