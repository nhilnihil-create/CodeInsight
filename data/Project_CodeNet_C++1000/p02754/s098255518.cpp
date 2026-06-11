#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long long n,a,b;
    cin >> n >> a >>b;
    if(a==b && a==0){
        cout << 0 <<endl;
    }else{
        long long ans = n/(a+b);
        cout << a*ans + min(a,n-(ans*(a+b))) <<endl;
    }
}