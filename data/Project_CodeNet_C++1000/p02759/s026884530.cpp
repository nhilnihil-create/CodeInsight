#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main()
{
    int n, sheet;
    cin >> n;
    if(n % 2 == 0)
    {
        sheet = n / 2;
    }
    else if(n % 2 != 0)
    {
        sheet = n / 2;
        sheet++;
    }
    cout << sheet << endl;
    return 0;
}

