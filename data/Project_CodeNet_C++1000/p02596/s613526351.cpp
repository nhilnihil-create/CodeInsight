#include <bits/stdc++.h>
#include<iostream>
#include <math.h>//pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm>//sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init,i,n) for (int i=init; i <(n);i++)
#define ll long long
#define rev(s) reverse(s.begin(),s.end())
#define sor(v) sort(v.begin(),v.end())

using namespace std;


int main() {
ll K;
cin>>K;

ll L = 7;
ll LmodK = L%K;

rep(1,i,K+1){
if(LmodK == 0){
cout<<i<<endl;return 0;
}
LmodK = LmodK*10+7;
LmodK %= K;
}

cout<<-1<<endl;

/*
ll K,L;
cin>>K;

if(K==7 || K==1){cout<<1<<endl;return 0;}


L = 9*K;


//cout<<"L="<<L<<endl;//

ll M = 70;

rep(0,i,K+1){

    //cout<<"M="<<M<<endl;//
    
    
    

    if(M%L==7){
        //cout<<"ans="<<i<<endl;return 0;
        cout<<i+1<<endl;return 0;
    }
    M = M%L*10+7;
}

cout<<"ans="<<-1<<endl;
*/

}
