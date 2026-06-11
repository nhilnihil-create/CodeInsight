#include<iostream>
using namespace std;



int main()
{
    int N,digit,temp=0;
    cin >> N;
    while (N != 0)
    {
        digit = N % 10;
        if (digit == 7)
        {
            temp=1;
            break;
        }
        N = N / 10;
    }
    if (temp == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
