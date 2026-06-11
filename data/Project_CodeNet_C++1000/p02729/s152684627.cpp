#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n>> m;
    if(n>=2&&m>=2){
        cout << n*(n-1)/2 + m*(m-1)/2;
    }
    else if(n==1 && m==1){
        cout << 0;
    }
    else{
        cout << max(n,m)*(max(n,m)-1)/2;
    }
}