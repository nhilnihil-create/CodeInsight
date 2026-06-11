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
                if(i % 2 == 0)
                {
                    for(int c = 0; c < h; c++)
                    {
                        if(c % 2 == 0)
                            cout << '#';
                        else
                            cout << '.';
                    }
                }
                
                else
                {
                    for(int c = 0; c < h; c++)
                    {
                        if(c % 2 == 1)
                            cout << '#';
                        else
                            cout << '.';
                    }
                }
  
                cout << endl;
            }
        
        cout << endl;
    }while(true);

    return 0;
}