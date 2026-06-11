#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(void)
{
    int N;
    cin >> N;

    switch (N%10)
    {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            cout << "hon";
            break;
        case 3:
            cout << "bon";
            break;
        default:
            cout << "pon";
            break;
    }

    return 0;
}
