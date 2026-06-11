#include <bits/stdc++.h>
using namespace std;
#define LL long int
#define ULL unsigned long int
#define LD long double

LL MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(),a.end());

    int ans = 0;
    vector<int> num(a.back() + 1);
    for(int i = 0; i < n; ++i){
        num[a[i]]++;
    }

    vector<bool> f(a.back() + 1, true);

    for(int i = 0; i < n; ++i){
        if(f[a[i]]){
            if(num[a[i]] == 1){
                ans++;
            }
            for(int j = a[i]; j <= a.back(); j = j + a[i]){
                f[j] = false;
            }
        }
    }

    cout << ans << endl;

    return 0;
}