#include <iostream>
using namespace std;

int main(){
    //input
    int m1, d1, m2, d2;
    scanf("%d%d", &m1, &d1);
    scanf("%d%d", &m2, &d2);

    //judge
    if(m1 != m2) cout << "1" << endl;
    else cout << "0" << endl;

    return 0;
}