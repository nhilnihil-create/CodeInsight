#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

bool check_prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int x;
    cin>>x;
    while(!check_prime(x)) x++;
    cout<<x<<endl;
}