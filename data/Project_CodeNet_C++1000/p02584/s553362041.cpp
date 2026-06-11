#include <iostream>
using namespace std;

int main(){
    long long X,K,D; cin >> X >> K >> D;
    long long S = abs(X)/D;
    if(S>=K){
        cout << abs(X+((X>0)?-1:1)*D*K) << endl;
    } else {
        if(X>0){
            X -= D*S;
            K -= S;    
            cout << abs(X-((K%2)?D:0)) << endl;
        } else {
            X += D*S;
            K -= S;
            cout << abs(X+((K%2)?D:0)) << endl;
        }
    }
}