#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    long long X, K, D;
    cin >> X >>K >> D;
    X=abs(X);
    D=abs(D);

    long long sho = X/D;
    long long amari = X%D;

    if(sho >= K){
        cout << X- K*D << endl;
    }
    else{
        K-=sho;
        if(K%2 ==0){
            cout << amari << endl;
        }
        else{
            cout << abs(amari-D) << endl;
        }
    }
    
    

    return 0;
}