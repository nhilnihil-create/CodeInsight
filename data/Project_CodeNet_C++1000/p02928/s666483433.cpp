/**
*    author:  souzai32
*    created: 13.08.2020 10:05:23
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long long n,k;
    cin >> n >> k; 
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    long long ans=0, count=0, num;
    rep(i,n-1){
        for(int j=n-1; j>i; j--) if(a.at(i)>a.at(j)) ans++;
    }
    ans*=k;
    ans%=long(1e9+7);
    
    sort(a.begin(),a.end(),greater<>());
    long long b=n*(n-1)/2;
    rep(i,n-1){
        if(a.at(i)==a.at(i+1)) count++;
        else count=0;
        b-=count;
        // cout << count << endl;
    }
    // cout << b << endl;
    if(k%2){
        b*=k;
        b%=long(1e9+7);
        b*=(k-1)/2;
        b%=long(1e9+7);
    }
    else{
        b*=k/2;
        b%=long(1e9+7);
        b*=k-1;
        b%=long(1e9+7);
    }
    ans+=b;
    ans%=long(1e9+7);
    // cout << b << endl;

    cout << ans << endl;

    return 0;
}
