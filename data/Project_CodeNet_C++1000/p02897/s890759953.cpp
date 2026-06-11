#include <iostream>
using namespace std;
int main(){
    int n, i, num;
    cin >> n;
    num = 0;
    for (i = 1; i <= n; i++){
        if (i % 2 == 1){
            num++;
        }
    }
    cout << (double)num / n << endl;
    return 0;
}
