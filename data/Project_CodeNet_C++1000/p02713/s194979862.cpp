#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int c){
    int m = min(a,min(b,c));
    for(int i=m;i>=1;i--){
        //cout << i << endl;
        //cout << a%i << b%i << c%i << endl;
        if(a % i == 0 && b % i == 0 && c % i == 0) return i;
    }
}

int main(){
    int k;
    cin >> k;
    int sum = 0;
    gcd(4,4,3);
    for(int a=1;a<=k;a++){
        for(int b=1;b<=k;b++){
            for(int c=1;c<=k;c++){
                //cout << a <<"," << b << "," << c << "," <<gcd(a,b,c) << endl;
                sum += gcd(a,b,c);
            }
        }
    }

    cout << sum << endl;
}