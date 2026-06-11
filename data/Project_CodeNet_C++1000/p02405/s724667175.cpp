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
            for (int h=0; h<H; h++)
            {
                if (h%2==0)
                {
                    for (int w=0; w<W; w++)
                    {
                        if (w%2==0) cout << "#";
                        else cout << ".";
                        //cout << endl;
                    }
                }
                else
                {
                    for (int w=0; w<W; w++)
                    {
                        if (w % 2 == 1) cout << "#";
                        else cout << ".";
                        //cout << endl;
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
        else k = 10000;
    }
    return 0;
}