
#include "iostream"

using namespace std;

int return_multiple(int i, int j){
    return i * j;
}

int main(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            int k = return_multiple(i, j);
            cout << i << "x" << j << "=" << k << endl;
//            printf("%dx%d=%d\n", i, j, k);
        }
    }
    return 0;
}