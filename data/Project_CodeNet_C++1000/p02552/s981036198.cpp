#include <iostream>

using namespace std;

int main(){
    int x = 0;
    cin >> x;

    if(x == 0){
        x = 1;
    }else{
        x = 0;
    }

    cout << x << endl;

    return 0;
}