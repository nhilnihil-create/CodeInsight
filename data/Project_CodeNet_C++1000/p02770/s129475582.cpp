#include <bits/stdc++.h>

using namespace std;

int k,q;

long long modm(int x,int m){
    if(x%m == 0) return m;
    return x%m;
}
void solve(){
    int i,j;
    string str;
    cin >> k >> q;
    vector<long long> d(k);
    for(i = 0;i < k;i++) cin >> d[i];
    for(i = 0;i < q;i++){
        long long n,x,m;
        cin >> n >> x >> m;
        vector<long long> dm(k);
        for(j = 0;j < k;j++) dm[j] = modm(d[j],m);
        long long sd = 0;
        for(j = 0;j < k;j++) sd += dm[j];
        sd *= (n-1) / k;
        sd += x%m;
        for(j = 0;j < (n-1)%k;j++) sd += dm[j];
        cout << n-1-sd/m << endl;
    }
}

int main(){
    solve();
}
