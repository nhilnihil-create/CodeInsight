#include<bits/stdc++.h>
using namespace std;
long long X,K,D,XP,KHAR;
int main(){
    cin>>X>>K>>D;
    X=abs(X);
    KHAR=min(K,X/D);
    K-=KHAR;
    X-=KHAR*D;
    if(K%2==0){cout<<X;return 0;} 
    else{cout<<D-X;return 0;}
}