#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000101001;
int main(){
string s;cin>>s;
string st[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
rep(i,7){
    if(s==st[i]&&s!=st[6])cout<<7-i-1<<endl;
}
if(s==st[6])cout<<7<<endl;
}