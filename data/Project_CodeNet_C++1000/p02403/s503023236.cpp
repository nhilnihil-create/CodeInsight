#include <iostream>
#include <string>

using namespace std;

int main()
{
    int H, W;
    string line;

    while (cin >> H >> W)
    {
        if (H == 0 && W == 0)
        {
            break;
        }

        line = "";

        for (int x = 0; x < W; x++)
        {
            line += "#";
        }

        for (int y = 0; y < H; y++)
        {
            cout << line << endl;
        }
        
        cout << endl;
    }

    return 0;
}

