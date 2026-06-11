#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<queue>
#include<cstdio>
#include<vector>
#include <algorithm>
#include<string>
#define rep(i,n) for (int i=0;i<(n);++i)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(char c : s){
        ans += (c-'0');
    }
    if(ans%9==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}