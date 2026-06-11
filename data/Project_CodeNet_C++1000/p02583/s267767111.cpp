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
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            for(int k = j+1; k < n; ++k){
                if(a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[k] + a[j] > a[i] && a[i] != a[j] && a[j] != a[k] && a[i] != a[k]){
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}