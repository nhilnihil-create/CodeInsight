#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a%b){
        return gcd(b,a%b);
    } else {
        return b;
    }
}

int main(){
    int n; cin >> n;
    long long ans=0;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            for(int c=1; c<=n; c++){
                ans += gcd(gcd(a,b),c);
            }
        }
    }
    cout << ans << endl;
}