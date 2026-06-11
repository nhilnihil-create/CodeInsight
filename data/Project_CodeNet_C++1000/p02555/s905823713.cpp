#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;

typedef long long ll;
ll a[maxn];
const int mod = 1e9+7;
int ans;
void search(int sum) {

    if(sum < 3) {
        if(sum == 0) {
            ans ++;   
        }
        return;
    }
    for(int i = 3;i <= sum;i ++) {
        search(sum - i);
    }
}
int main() {
    int S;
    cin>>S;
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    a[4] = 1;
    a[5] = 1;
    for(int i = 6;i <= S;i ++){
        a[i] = (a[i-1] + a[i-3])%mod;
    }
    cout<<a[S]<<endl;
    return 0;
}

