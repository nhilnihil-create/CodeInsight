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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int p1=0,p2=2;
    int count=0;
    while(p2>p1){
        string s=str.substr(p1,3);
        if(s=="ABC")
            count++;
        p1++;
        if(p2!=str.size()-1)
            p2++;
    }
    cout<<count<<endl;
    return 0;
}

