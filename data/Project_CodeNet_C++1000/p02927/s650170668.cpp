#include <iostream>
using namespace std;

int main(){
    int m, d;cin>>m>>d;
    int acc = 0;
    for (int i=1;i<=m;i++){
        for (int j=10;j<=d;j++){
            int ten = j / 10;
            int one = j % 10;
            if (ten >= 2 && one >= 2 && ten * one == i){
                acc++;
            }
            
        }
    }
    cout << acc << endl;
    return 0;
}