#include<iostream>
using namespace std;

int main()
{
    int H, W;

    for (int k = 0; k<10000; k++)
    {
        cin >> H >> W;
        if (H != 0 && W != 0)
        {
            for (int x=1; x<=W; x++)
            {
                cout << "#";
            }
            cout << endl;
            for (int i=3; i<=H; i++)
            {
                cout << "#";
                for (int j=1; j<=W-2; j++)
                {
                    cout << ".";
                }
                cout << "#" << endl;
            }
            for (int x=1; x<=W; x++)
            {
                cout << "#";
            }
            cout << "\n" << endl;
        }
        else k = 10000;
    }
    return 0;
}