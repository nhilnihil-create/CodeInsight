#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int h, w;

    while(true)
    {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }
        
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(i==0 || j==0 || i==h-1 || j==w-1)
                {
                    printf("#");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}

