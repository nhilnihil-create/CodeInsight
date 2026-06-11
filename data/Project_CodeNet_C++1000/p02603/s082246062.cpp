#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 200000
#define ll long long
using namespace std;

int main(){
    int n; cin>>n;
    int data[n];
    ll money=1000;
    ll stock=0;
    for(int i=0; i<n; i++) cin>>data[i];
    
    for(int i=0; i<n-1; i++){
        if(data[i]>data[i+1]){
            money+=data[i]*stock;
            stock=0;
        }
        else{
            ll p=money/data[i];
            stock+=p;
            money-=p*data[i];
        }
    }
    money+=data[n-1]*stock;
    
    cout<<money<<endl;
}