#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long

    int main (){
        int k,n;
        cin >> k >> n;
        vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    int ans =a[n-1]-a[0];

for(int i =0;i+1<n;i++){
    ans =  min(ans,k-(a[i+1]-a[i]));
}
cout << ans << endl;
return 0;

    }