#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

int main(){
    int D;
    cin>>D;
    vector<long int> c(26);
    rep(i,26) cin>>c[i];
    vector<vector<long int> > s(D,vector<long int>(26));
    rep(i,D){
        rep(j,26) cin>>s[i][j];
    }
    vector<long int> t(D);
    rep(i,D){
        cin>>t[i];
        t[i]--;
    }
    vector<int> last(26,-1);
    vector<long int> ans(D+1);
    for(int i=0;i<D;i++){
        ans[i+1]=ans[i]+s[i][t[i]];
        rep(j,26){
            if (t[i]==j) last[j]=i; 
            ans[i+1]-=c[j]*(i-last[j]);
        }
    }
    for (int i=1;i<D+1;i++)  cout<<ans[i]<<endl;
    return 0;
}