#include<iostream>
#include <cstring>
using namespace std;
int main() {
    int a = 0, b = 0;
    char S[200001] , T[200001];
    cin >> S; cin >> T;
    for (int i = 0; i <= strlen(S); i++){
        if (S[i] == T[i]) b++;
        else a++; }
    if (0 == a && 0==b ) cout << b;
    else  cout << a;
    return 0;

}