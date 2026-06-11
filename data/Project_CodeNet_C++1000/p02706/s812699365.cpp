#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, sum=0, cnt=0, ans;
    cin >> n >> m;
    vector<long long> a(m);
 
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
        cnt++;
    }
    if(n >= sum) {
        ans = n-sum;
        cout << ans << endl;
    }else{
        cout << "-1" << endl;
    }
 
    return 0;
}
 
long long facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}