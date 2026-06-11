#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int a;
    cin>>a;
    switch(a % 10)
    {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
        cout<<"hon";break;
    case 0:
    case 1:
    case 6:
    case 8:
        cout<<"pon";
        break;
    case 3:
        cout<<"bon";
    }

    return 0;
}
