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
//#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;

int po(int n){
    int a=1;
    if (n<0) return 0;
    for (int i=0;i<n;i++) a*=10;
    return a;
}

long int f(int n,int i, int j){
    long int ans=0;
    int d=1,m=n;
    while(m/10){
        m=m/10;
        d++;
    }
    for (int i=2;i<=d-1;i++){
        ans+=po(i-2);
    }
    if (i==j && i<=n) ans++;
    if (i<m) ans+=po(d-2);
    if (i==m && d>=2){
        int s=(n-m*po(d-1))/10,t=n%10;
        ans+=s+1;
        if (t<j) ans--;
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    long int ans=0;
    for (int i=1;i<10;i++){
        for (int j=1;j<10;j++){
            ans+=f(N,i,j)*f(N,j,i);
        }
    }
    cout<<ans<<endl;
    return 0;
}