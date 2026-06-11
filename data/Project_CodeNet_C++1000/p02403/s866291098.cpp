#include <iostream>
using namespace std;

void printRect(int w, int h)
{
    while (h-- > 0)
    {
        for (int x = 0; x < w; x++)
        {
            cout << '#';
        }
        cout << endl;
    }
}

int main(void)
{
    while (1)
    {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0)
            break;
        printRect(w, h);
        cout << endl;
    }
    return 0;
}