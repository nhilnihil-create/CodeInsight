#include <iostream>
using namespace std;
int main()
{
    int K , X , Y, into;
    cin >> Y >> X;
    K = 500;
    into = K*Y;
    if (into >= X) cout << "Yes" << endl ;
    else cout << "No" << endl;
    return 0;
}