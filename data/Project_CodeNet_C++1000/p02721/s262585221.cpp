#include <math.h>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#include<stdio.h>
#include <iostream>
#include <vector>
#include <set>
//#include <string.h>
using namespace std;
using Graph = vector<vector<int>>;
queue<long>que;

int main(){
    int n,k,c;
    string s;
    cin>>n>>k>>c;
    cin>>s;
    vector<int>day1(n,0);
    vector<int>day2(n,0);
    rep(i,n){
        if(s.at(i)=='x'){
            day1[i]=-1;
            day2[i]=-1;}
    }
    int cnt = 1;
    rep(i,n){
        if(day1[i]==-1)continue;
        day1[i] = cnt;
        cnt++;
        i+=c;
        if(cnt == k+1)
            break;
    }
    cnt = k;
    for(int i = n-1;i>=0;i--){
        if(day2[i]==-1)continue;
        day2[i] = cnt;
        cnt--;
        i-=c;
    }
    rep(i, n){
        if(day1[i]>0 && day1[i]==day2[i])
            cout<<i+1<<endl;
    }
    
    

}
