#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e9+7;

int mul(int a, int b){
    return 1LL*a*b%M;
}

int add(int a, int b){
    return (a%M+b%M)%M;
}

int sub(int a, int b){
    return ((a%M - b%M)+M)%M;
}

int pow(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1) res = mul(res,a);
        a = mul(a,a);
        b/=2;
    }
    return res%M;
}

int main(){
    int n,k;
    cin>>n>>k;

    int res = 0;
    int arr[k+1];
    for(int i = k; i >= 1; i--){
           int t = pow(k/i, n); 
           for(int j = i*2; j<=k; j+=i) t = sub(t,arr[j]);
           res = add(res,mul(t,i));
           arr[i] = t;
    }
    cout<<res;
}
