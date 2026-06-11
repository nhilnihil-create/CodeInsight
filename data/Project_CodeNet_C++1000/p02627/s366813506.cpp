#include <bits/stdc++.h>
using namespace std;

int main(){
    char a;
    cin >> a;
    if('A' <= a && a <= 'Z') {
        cout << "A" << endl;
    } else if('a' <= a && a <= 'z') {
        cout << "a" << endl;
    }
    return 0;
}