#include <iostream>
using namespace std;

int main (){
    int n,j;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> j;
        if(j % 2 == 0 && j % 3 != 0 && j % 5 != 0) {
            cout << "DENIED" << endl;
            return 0;
        }
    }

    cout << "APPROVED" << endl;

    return 0;

}