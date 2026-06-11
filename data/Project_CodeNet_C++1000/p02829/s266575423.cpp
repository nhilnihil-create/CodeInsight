#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    for(int i = 1; i <= 3; i++){
        if(A != i && B != i){
            cout << i << endl;
            return 0;
        }
    }
}