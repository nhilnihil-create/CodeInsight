
#include <iostream>
using namespace std;
int main(void){
    int x, y, z;
    cin >> x >> y >> z;
    
    int tmp = x;
    x = y;
    y = tmp;
    int temp = x;
    x = z;
    z = temp;
    
    printf("%d %d %d\n", x, y, z);
    
}
