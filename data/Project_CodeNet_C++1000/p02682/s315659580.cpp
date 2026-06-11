#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<long int> sieve(long int n){
    long int arr[n+1];
    for(long int i = 0; i <= n;++i){
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    long int p= 2;
    while(p <= n){
        if(arr[p]){
            for(long int i = p*2; i <=n; i+=p){
                arr[i] = 0;
            }
        }
        p++;
    }
    vector<long int> ans;
    for(long int i = 2; i < n ; i++){
        if(arr[i]){
            ans.push_back(i);
        }
    }
    return ans;
    }
int main(){
    int a,b,c,k, ans=  0;
    cin>>a>>b>>c>>k;
    if(k > 0){
        int val = min(a,k);
        ans+=val;
        k-=val;
    }
    if(k > 0){
        int val = min(b, k);
        k-=val;
    }
    if(k >0){
        int val = min(c,k);
        k-=val;
        ans-=val;
    }
    cout<<ans<<endl;
}