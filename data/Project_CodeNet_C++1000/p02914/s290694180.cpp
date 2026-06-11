//
//  main.cpp
//  F
//
//  Created by 曾憲揚 on 2020/9/7.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
typedef long long ll;
ll a[N];

ll umin(ll a, ll b){
    return a<b? a:b;
}
ll umax(ll a, ll b){
    return a>b? a:b;
}

ll maxor(int n){
    int rank=0;
    
    int j;
    for(int i=59; i>=0; i--){
        for(j=rank; j<n; j++){
            if(a[j]& (1LL<<i)) break;
        }
        if(j==n) continue;
        
        if(j>rank) swap(a[j], a[rank]);
        
        for(j=rank+1; j<n; j++){
            a[j]=min(a[j], a[j]^a[rank]);
        }
        
        rank++;
    }
    ll ans=0;
    for(int i=0; i<n; i++)
        ans=umax(ans, ans^a[i]);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin>>n;
    
    ll all=0;
    for(int i=0; i<n; i++){
        cin >>a[i];
        all^=a[i];
    }
    for(int i=0; i<n; i++){
        a[i] &= (~all);
    }
    
        
    ll ans = all+2*maxor(n);;
    
    cout<<ans<<endl;
    return 0;
}
