#include <iostream>
#include <cmath>
using namespace std;


int main(void)
{
    //const double PI=3.141592653589793238;


    long long a, b, c, judge=-1, _judge=-1;
    cin >> a >> b >> c;

    if(a+b-c>0) cout << "No" << endl;
    else if(((a+b-c)*(a+b-c) > 4*a*b)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}