//
// Created by kashi on 27-07-2020.
//
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define Endl endl
#define int long long
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
bool cmps(pair<int,int>p1,pair<int,int>p2) {
    return p1.ss<p2.ss;
}
int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}
int32_t main() {
    int k,x;
    cin>>k>>x;
    if(k*500>= x)
        cout<<"Yes"<<Endl;
    else cout<<"No"<<Endl;
    return 0;
}
