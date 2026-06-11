#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a12, a13, a23,d1,d2,d3,mini;
    cin >>a12 >>a13>>a23;
    d1=a12+a13;
    d2=a12+a23;
    d3=a13+a23;
    mini=min({d1,d2,d3});
    cout << mini ;
    return 0;
}
