#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    ll x;
    cin>>x;
    ll k=0;
    ll a,b;
    ll i=0,j=0;
    while(k<x){
        a=pow(i,5);
        j=0;
        while(j<i){
            b=pow(j,5);
            k=a-b;
            if(a+b==x){
                cout<<i<<" "<<j*-1<<endl;
                return 0;
            }
            if(k==x) {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
            j++;
        }
        i++;
    }
}
