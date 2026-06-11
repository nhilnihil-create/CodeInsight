#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define ll long long
using namespace std;

int n;

void dfs(string s, char mx){
    if(s.size()==n) cout<<s<<endl;
    else{
        for(char i='a'; i<=mx; i++) dfs(s+i, ((i==mx) ? mx+1 : mx));
    }
}

int main(){
    cin>>n;
    dfs("",'a');
}