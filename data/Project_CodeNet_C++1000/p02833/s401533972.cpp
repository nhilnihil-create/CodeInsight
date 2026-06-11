#include <bits/stdc++.h>
using namespace std;


int main(){

    long long int n;
    cin >> n;
    long long int ans=0;
    long long five=10;

    if(n%2==1) cout << 0 << endl;
    else{
        while(1){
            if(five>n) break;
            ans+=n/five;
            five*=5;
        }
        cout << ans << endl;
    }
}