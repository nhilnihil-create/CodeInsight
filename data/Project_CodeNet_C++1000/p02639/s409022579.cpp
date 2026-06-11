#include <iostream>
#define DATA_NUM 5

using namespace std;

int main(){
    int x;

    for(int i = 1; i <= DATA_NUM; i++){
        cin >> x;
        if(x == 0){
            cout << i << endl;
            break;
        }
    }

    return 0;
}