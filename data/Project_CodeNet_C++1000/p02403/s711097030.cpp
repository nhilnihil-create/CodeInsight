#include <iostream>
using namespace std;

void writeRectangle(int w, int h)
{
    for (int i=0; i<w; ++i)
    {
        for (int j=0; j<h; ++j)
        {
            cout << '#';
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