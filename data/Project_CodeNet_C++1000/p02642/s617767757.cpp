#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN]={0};
map<int,int>mm;
int solve(int n){
    if(mm[n]>1||(mm[1]&&n!=1))
        return 0;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            mm[n]--;
            if(mm[n/i]||mm[i]){
                mm[n]++;
                return 0;
            }
            mm[n]++;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mm[a[i]]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=solve(a[i]);
    }
    cout <<ans << endl;
    return 0;
}
