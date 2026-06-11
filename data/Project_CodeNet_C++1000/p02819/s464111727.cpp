#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    int x;
    cin >> x;
    for(int h=x;h<=1000000;h++){
        bool isprime=true;
        for(int i=2;i*i<=h;i++){
            if(h%i == 0){
                isprime=false;
                break;
            }
        }
        if(isprime){
            cout << h << endl;
            break;
        }
    }
    return 0;
}
