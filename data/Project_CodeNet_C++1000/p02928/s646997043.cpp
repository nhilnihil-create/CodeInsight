#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
using namespace std;


int main(){
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(2*n);
    for(long long int i=0;i<n;i++) cin >> a[i];
    for(long long int i=n;i<2*n;i++) a[i] = a[i-n];

    long long int res = 0;

    // aの中にある転倒数
    for(long long int i=0;i<n-1;i++){
        for(long long int j=i+1;j<n;j++){
            if(a[i] > a[j]) {
                res++;
            }
        }
    }

    //aを跨いで存在する転倒数
    long long int res1 = 0;
    for(long long int i=0;i<n;i++){
        for(long long int j=n;j<2*n;j++){
            if(a[i] > a[j]){
                res1++;
            }
        }
    }
    long long int ans = k*res%1000000007;
    ans += res1 * (((k-1)*k)/2 % 1000000007)%1000000007;
    ans %= 1000000007;

    cout << ans << endl;
}
