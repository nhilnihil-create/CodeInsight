#include <iostream>

using namespace std;
// int n = 7;  int a[] = {4,2,5,3,5,8,3}; sort(a,a+n)
int main() {
    int a, b;
    cin >> a >> b;
    int g;
    int l;
    if(a >= b){
        g = a;
        l = b;
    } else{
        g = b;
        l = a;
    }
    for(int i = 0; i < g; i++){
        cout << l; 
    }
    return 0;
}