#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll int n,min=100000,a[3001],b[3001];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if(i==0){
            b[0]=a[0];
        }else{
            b[i]=b[i-1]+a[i];
        }
    }
    for(int i=0;i<n-1;i++){
        if(min>abs(b[n-1]-2*b[i])){
            min=abs(b[n-1]-2*b[i]);
        }
    }
    cout << min;
}