#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){

    int K;
    string S;
    
    cin >> K;
    cin >> S;
    
    if(K>=S.size()) cout << S;
    if(K<S.size()) {
        S = S.substr(0,K) + "...";
        cout << S;
    }
}