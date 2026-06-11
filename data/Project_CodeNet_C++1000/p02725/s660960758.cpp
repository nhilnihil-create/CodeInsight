#include<bits/stdc++.h>

using namespace std;

int main(){
int n, i, right, left, ans = 0, k;
cin >> k >> n;
int a[n];
for(i=0; i<n; i++) cin >> a[i];

if(n == 1) ans = 0;
else if(n==2){
    ans  = min(k-abs(a[0]-a[1]), abs(a[0]-a[1]));
}
else {
    int segment[n] = {0}, sum = 0, ans = INT_MAX;
    for(i=0; i<n-1; i++){
        segment[i] = abs(a[i]-a[i+1]);
        sum += segment[i];
    }
    segment[i] = k-a[n-1]+a[0];
    sum += segment[i];
    for(i=0; i<n; i++){
        ans = min(ans, sum-segment[i]);
    }
    cout << ans;
}

}
