#include <bits/stdc++.h>
#include<iostream>
#include <math.h>//pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm>//sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init,i,n) for (int i=init; i <(n);i++)
#define ll long long
#define rev(s) reverse(s.begin(),s.end())
#define sor(v) sort(v.begin(),v.end())
//コード自動整形 Shift + Alt + F @vscode
using namespace std;


/////main/////
int main() {
ll N,D;
cin>>N>>D;
vector<ll> X(N);
vector<ll> Y(N);
rep(0,i,N){
    cin >> X.at(i)>>Y.at(i);
}
ll cnt = 0;

rep(0,i,N){
    if(D*D>=(X.at(i)*X.at(i)+Y.at(i)*Y.at(i))){
        cnt++;
    }
}
cout<<cnt<<endl;
return 0;
}
/////main/////

/////function/////