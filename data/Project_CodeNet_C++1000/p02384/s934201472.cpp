#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

class Dice
{
public:
    int f[6];
    Dice(){}
    void roll_z(){ roll(1, 2, 4, 3); }
    void roll_y(){ roll(0, 2, 5, 3); }
    void roll_x(){ roll(0, 1, 5, 4); }
    void roll(int i, int j, int k, int l){
        int t = f[i];
        f[i] = f[j];
        f[j] = f[k];
        f[k] = f[l];
        f[l] = t;
    }
    void move(char ch){
        if (ch == 'E') for (int i = 0; i < 3; i++) roll_y();
        if (ch == 'W') roll_y();
        if (ch == 'N') roll_x();
        if (ch == 'S') for (int i = 0; i < 3; i++) roll_x();
    }
};

int main()
{
    Dice dice;
    string dir;
    int q;
    for (int i = 0; i < 6; i++)
        cin >> dice.f[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int up, front, flag = 0;
        cin >> up >> front;
        while (1)
        {
            if (dice.f[0] == up)
            {
                flag = 1;
                break;
            }
            if (dice.f[1] == front)
            {
                flag = 2;
                break;
            }
            dice.roll_x();
        }
        while (1)
        {
            if (flag == 1)
            {
                if (dice.f[1] == front)
                {
                    break;
                }
                dice.roll_z();
            }
            else 
            {
                if (dice.f[0] == up)
                {
                    break;
                }
                dice.roll_y();
            }
        }
        cout << dice.f[2] << endl;
    }
    return 0;
}
