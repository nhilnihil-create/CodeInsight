#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, left_number;

    cin >> n;

    left_number = (n % 10);
    
    switch(left_number)
    {
        case 3:
            printf("bon\n");
            break;
        case 0:
        case 1:
        case 6:
        case 8:
            printf("pon\n");
            break;
        default:
            printf("hon\n");
            break;
    }

    return 0;
}