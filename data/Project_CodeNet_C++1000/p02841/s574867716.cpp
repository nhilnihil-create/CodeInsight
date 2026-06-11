#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n[4];
    for (int i = 0; i < 4;i++){
        cin >> n[i];
    } 
    if(n[2]-n[0]==1){
        cout << 1;
    }else
        cout << 0;
    return 0;
}