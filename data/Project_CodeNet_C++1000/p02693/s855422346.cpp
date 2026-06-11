#include <iostream>
using namespace std;

 
 
int main()
{
    int k, a, b;
 
    cin >> k >> a >> b;
 
    int x = b/k - (a-1)/k;
 
    if(x == 0){
        cout << "NG" << endl;
    } else {
        cout << "OK" << endl;
    }
 
    return 0;
}