#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n;
    cin >> n;
    vector<int> a(n);
    int amax = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        amax = max(amax, a[i]);
    }

    sort(all(a));
    vector<bool> check(amax + 1, true);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        //if(check[a[i]] == false) continue;
        if(a[i-1] != a[i] && a[i] != a[i+1]){
            ans += check[a[i]];
        }

        for(int j = a[i]; j <= amax; j += a[i]){
            check[j] = false;
        }
    }

    cout << ans << "\n";

    return 0;
}
