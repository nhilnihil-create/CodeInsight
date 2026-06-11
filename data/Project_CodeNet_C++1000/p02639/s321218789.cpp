/**
*    author:  Taichicchi
*    created: 07.09.2020 00:30:52
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    for(int i=1;i<6;++i){
        int x;
        cin >> x;
        if(x == 0){
            cout << i << endl;
            break;
        }
    }

    return 0;
}