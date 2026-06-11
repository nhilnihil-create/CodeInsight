#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int a ,b;
    cin>>a>>b;
    int sum;
    sum = max(0, a-2*b);
    cout<< sum << endl;
    return 0;
}