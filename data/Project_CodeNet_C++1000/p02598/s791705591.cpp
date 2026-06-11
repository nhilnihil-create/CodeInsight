/**
*    author:  souzai32
*    created: 12.08.2020 15:37:08
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());

    int left=1,right=a.at(n-1),mid;
    int count;
    int ans=right;

    while(left<right){
        mid=(left+right)/2;
        count=0;
        for(int i=0; i<n; i++) count+=(a.at(i)-1)/mid;
        if(count<=k){
            ans=min(mid,ans);
            right=mid;
        }
        else left=mid+1;
    }
    
    cout << ans << endl;

    return 0;
}