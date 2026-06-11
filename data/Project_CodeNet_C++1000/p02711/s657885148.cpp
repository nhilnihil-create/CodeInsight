/**
*    author:  Taichicchi
*    created: 07.09.2020 00:30:52
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string N;

    cin >> N;

    for(int i=0;i<3;++i){
        if(N[i] == '7'){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}