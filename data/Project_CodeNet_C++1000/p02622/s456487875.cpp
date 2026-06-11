#include <iostream>
using namespace std;
int main(void){
    string S, T;
    int B = 0;
    cin >> S >> T;
    for (int i = 0; i < S.size(); i++){
        if (S.at(i) != T.at(i)){
        B++;
}
}
cout << B;
}
