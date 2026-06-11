#include<bits/stdc++.h>
using namespace std;

vector<int> a(20000000);

int main(){
    int n; cin >> n;
    long long sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];  sum += a[i];
    }
    long long ans=sum, dis=0;
    for(int i=0; i<n; i++){
        dis += a[i];
        ans = min( ans, abs(dis - (sum - dis)));
    }
    
    cout << ans << endl;
    return 0;
}