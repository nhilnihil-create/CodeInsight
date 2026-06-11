#include <iostream>
using namespace std;

void writeRectangle(int w, int h)
{
    const char sharp = '#';
    const char dot = '.';

    char c = ' ';
    for (int i=0; i<w; ++i)
    {
        for (int j=0; j<h; ++j)
        {
            c = (((i%2 == 0)&&(j%2 == 0)) || ((i%2 == 1)&&(j%2 == 1))) ? sharp : dot;
            cout << c;
        }
        cout << endl;
    }
}

int main()
{
    int w=0, h=0;
    
    while(true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)   break;

        writeRectangle(w, h);
        cout << endl;
    }
    
    return 0;
}