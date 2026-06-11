#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int n){
    for(int j=2;j<=floor(sqrt(n));j++){
        if (n % j == 0) return false;
    }
    return true;
}

int main(){
    bool p[246952];
    for(int j=2;j<246942;j++){
        p[j] = isprime(j);
    }
    int n;
    while(cin >> n && n>0) {
        int cnt=0;
        for(int j=n+1;j<=2*n; j++){
            if (p[j]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}