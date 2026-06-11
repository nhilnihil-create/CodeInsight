#include <bits/stdc++.h>
using namespace std;

int main (){
    int A,B;
    cin >> A;
    cin >> B;

    vector <int>option = {1 , 2, 3};
    for (int i = 0; i < 3; i++){
        if (option.at(i) == A || option.at(i) == B)
            option.at(i) = -1;
    }
    for (int i = 0; i < 3; i++){
        if (option.at(i) != -1)
            cout << option.at(i) << endl;
    }
}