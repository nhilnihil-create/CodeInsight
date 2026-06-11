#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll sum=0;
    char n[200000];
    scanf("%s", &n);
    for(int i=0;i<strlen(n);++i){
        sum+= n[i]-'0';
    }
    if(sum%9==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}