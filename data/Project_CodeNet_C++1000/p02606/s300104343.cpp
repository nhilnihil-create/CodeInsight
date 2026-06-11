/*
    Vora Mahammadasim
*/

#include<bits/stdc++.h>
#include<stdio.h>
#define int long long
#define pb emplace_back
#define Mod 1000000007
#define all(a) a.begin(),a.end()
#define ps(a) partial_sum(all(a),a.begin())
using namespace std;





signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;cin>>a>>b>>c;
    int ans = 0;
    for(int i = a;i<=b;i++){
        if(i % c == 0) ans++;
    }
    cout<<ans;
}
