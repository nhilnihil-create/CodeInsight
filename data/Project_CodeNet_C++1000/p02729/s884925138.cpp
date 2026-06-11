#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,m;
    cin >> n >> m;
    int z = n - 1;
    int l = m - 1;
    
    int x = n * z;
    int a = x / 2;
    int y = m * l;
    int b = y / 2;
    
    cout << a + b << endl;
}