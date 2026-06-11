#include <iostream>
#include <string>

using namespace std;

int main()
{
    int H, W;
    string line, p;

    while (cin >> H >> W)
    {
        if (H == 0 && W == 0)
        {
            break;
        }

        for (int y = 0; y < H; y++)
        {
            line = "";
            p = "";

            for (int x = 0; x < W; x++)
            {
                if (x == 0 || x == W - 1)
                {
                    p = "#";
                }
                else
                {
                    if (y == 0 || y == H - 1)
                    {
                        p = "#";
                    }
                    else
                    {
                        p = ".";
                    }
                }

                line += p;
            }

            cout << line << "\n";
        }
        
        cout << "\n";
    }

    return 0;
}

