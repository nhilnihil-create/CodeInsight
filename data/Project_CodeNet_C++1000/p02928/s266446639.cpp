#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const long long int MOD = 1e9+7;

int main(){
    int  n;
    ll   k; 
    cin >> n >> k;
    vector<int> a;
    ll b_cnt=0;
    int max_n=0;
    for(int i=0; i<n; i++){
        int tmp = 0; cin >> tmp;
        if(tmp>max_n) max_n = tmp;
        a.push_back(tmp);
        for(int j=0; j<i; j++){
            if(a[j] > a[i]){
                b_cnt++;
            }
        }
    }
    b_cnt = b_cnt % MOD;
    
    ll ans =0;
    ans = b_cnt * k;
    ans = ans % MOD;

    ll c_cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i]>a[j]) c_cnt++;
        }
    }
    ll select = k*(k-1)/2;
    select = select % MOD;
    ans += select * c_cnt;
    ans = ans % MOD;

    cout << ans << endl;
    return 0;

}