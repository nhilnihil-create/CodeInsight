#include <iostream>
using namespace std;


int main(){
    int n, i, cou = 0, res;
    cin >> n;

    for(i = 1; i < 10; i++){
        res = n/i;
        if(res < 10 && n%i == 0){
            cou = 1;
            break;
        }
    }

    if(cou == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
