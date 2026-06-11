#include<iostream>
using namespace std;

void Cal(int Dice, int Time, int Sec)
{
    double temp = 0;
    temp = (double)Dice / Sec;
    if (temp <= Time)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    int Dice, Time, Sec = 0;
    cin >> Dice >>Time >>Sec;
    Cal(Dice, Time, Sec);


    return 0;
}