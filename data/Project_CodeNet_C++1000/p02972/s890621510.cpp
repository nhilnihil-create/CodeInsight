#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> cnt(n,0);
    for(int i=n-1; i>=0; i--){
        int sum = 0;
        for(int j=i*2+1; j<n; j+=(i+1)){
            //cout << j << endl;
            if(j>n) break;
            sum += cnt[j];
        }
        if(sum%2==0 && a[i]==0) cnt[i]=0;
        else if(sum%2==0 && a[i]==1) cnt[i]=1;
        else if(sum%2==1 && a[i]==0) cnt[i]=1;
        else if(sum%2==1 && a[i]==1) cnt[i]=0;
    }

    int m = 0;
    vector<int> ans;
    rep(i,n){
        if(cnt[i]==1){
            m++;
            ans.push_back(i+1);
        }
    }

    cout << m << endl;
    for(auto x: ans){
        cout << x << endl;
    }
}