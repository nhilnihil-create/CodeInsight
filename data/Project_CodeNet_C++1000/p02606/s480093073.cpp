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
    int l,r,d;
    cin>>l>>r>>d;
    int ans;
    ans=(r/d)-(l/d);
    if (l%d==0) ans++;
    cout<<ans<<endl;
    return 0;
}