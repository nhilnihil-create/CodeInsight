#include <iostream>

using namespace std;

int main(void)
{
    int X, Y, sum=0;

    cin >> X >> Y;

    if(X<=3){
        sum += (4-X) * 100000;
    }
    if(Y<=3){
        sum += (4-Y) * 100000;
    }

    if(X==1 && Y==1){
        sum += 400000;
    }

    cout << sum << endl;

    return 0;
}