#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int ans=n-1;

    for(long long int i=sqrt(n); i>0; i--){
        if(n%i==0){
            ans=n/i+i-2;
            break;
        }
    }
    cout << ans << endl;
}