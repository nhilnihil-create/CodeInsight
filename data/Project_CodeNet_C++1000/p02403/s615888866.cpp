#include <iostream>

using namespace std;

int main()
{
    int w, h;
    
    do
    {
        cin  >> w >> h;
        
        if(w == 0 && h == 0)
            break;
        
        else
            for(int i = 0; i < w; i++)
            {
                for(int c = 0; c < h; c++)
                    cout << '#';
                    
                cout << endl;
            }
        
        cout << endl;
    }while(true);

    return 0;
}