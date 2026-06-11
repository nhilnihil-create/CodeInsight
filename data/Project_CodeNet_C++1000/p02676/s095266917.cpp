#include <iostream>
#include <string>
using namespace std;
int main(void){
    
    int K;
    string S;
    cin >> K >> S;
    if(S.size() > K){
        cout << S.substr(0, K) << "..." << endl;;
    }
    else{
        cout << S << endl;
    }
    
}
