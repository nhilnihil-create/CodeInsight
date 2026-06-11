#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,k,q;
    cin >> n >> k >> q;
    vector <long> a(q);
    vector <long> dp(n+1,0);
    for(long i = 0; i < q; i++){
        cin >> a[i];
        dp[a[i]]++;
    }
    for(long i = 1; i <= n; i++){
        if(dp[i]-q+k<=0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}