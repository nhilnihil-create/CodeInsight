#include <iostream>
using namespace std;
  
int main()
{
    int h, w;
     
    do
    {
        cin  >> h >> w;
        if(h != 0 && w != 0)
        {
            for(int i = 1; i <= h; i++)
            {
                if(i == 1 || i == h)
                {
                    int n = 0;
                    while(n < w)
                    {
                        cout << '#';
                        n++;
                    }
                    cout << endl;
                }
                else
                {
                    int n = 1;
                    while(n <= w)
                    {
                        if(n == 1 || n == w)
                            cout << '#';
                        else
                            cout << '.';
                        n++;
                    }
                    cout << endl;
                }
             
            }
            cout << endl;
        }
    }while(h != 0 && w != 0);
     
    return 0;
}