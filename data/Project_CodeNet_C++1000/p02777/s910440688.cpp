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

int32_t  main(){
    string str1,str2;
    cin>>str1>>str2;
    int n1,n2;
    cin>>n1>>n2;
    string str3;
    cin>>str3;
    if(str3==str1)
        n1--;
    else
        n2--;
    cout<<n1<<" "<<n2<<endl;
    return 0;
}