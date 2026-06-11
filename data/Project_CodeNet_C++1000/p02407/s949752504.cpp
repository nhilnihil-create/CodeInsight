#include <iostream>
using namespace std;
int main(void){
    int n, a[100] = {0}; //100回
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = n-1; i > -1; i--) {
        if (i == n-1){
            cout << a[i];
        }
        else{
            cout << " " << a[i];
        }
    }
    cout << endl;
}
