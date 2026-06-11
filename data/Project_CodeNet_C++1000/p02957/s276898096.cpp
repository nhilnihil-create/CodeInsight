#include<iostream>
#include<cmath>
 
using namespace std;
 
int main() {
 
    long long int x, y, i = 1;
    int flag = 0;
    cin >> x >> y;
 
    while(i <= x || i <= y){
 
        if (abs(x - i) == abs(y - i)) {
            flag = 1;
            break;
        }
 
        i++;
    }
 
    if(!flag)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << i << endl;
 
    return 0;
}
