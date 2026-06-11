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
    long int K,n=0;
    long long ans=0;
    cin>>K;
    queue<long long> que;
    for (int i=1;i<10;i++) que.push(i);
    while(n<K-9){
        long long q=que.front();
        que.pop();
        if (q%10!=0){
            que.push(10*q+(q%10)-1);
            n++;
            if (n==K-9){
                ans=10*q+(q%10)-1;
                break;
            } 
        } 
        que.push(10*q+(q%10));
        n++;
        if (n==K-9){
            ans=10*q+(q%10);
            break;
        }  
        if (q%10!=9){
            que.push(10*q+(q%10)+1);
            n++;
            if (n==K-9){
                ans=10*q+(q%10)+1;
                break;
            } 
        } 
    }
    if (K<=9) cout<<K<<endl;
    else cout<<ans<<endl;

    return 0;
}