#include <iostream>
#include <string>

using namespace std;

int main(){
    int X, Y, a, b;
    bool flag = 0;

    cin >> X >> Y;

    //  a + b = X
    //  2a + 4b = Y

    for(int i = 0; i <= 100; i ++){
        for(int j = 0; j <= 100; j ++){
            if((i + j == X) && (2 * i + 4 * j == Y))flag = 1;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}