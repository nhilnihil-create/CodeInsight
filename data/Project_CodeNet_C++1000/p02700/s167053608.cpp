#include <iostream>
using namespace std;

int main() {
    int A,B,C,D;
    cin >> A>>B>>C>>D;
    int x,y = 0;
    do{
        A -= D;
        x++;
    } while (A > 0);
    do{
        C -= B;
        y++;
    } while (C > 0);
    if(x >= y) cout << "Yes";
    else cout << "No" ;

	return 0;
}