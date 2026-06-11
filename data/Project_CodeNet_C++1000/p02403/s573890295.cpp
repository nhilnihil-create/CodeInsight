#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    while (true) {
        u_int h, w;
        cin >> h >> w;
        if (!h && !w)
            break;
        
        char buf[w+2];
        for (u_int i = 0; i < w; i++)
            buf[i] = '#';
        buf[w] = '\n'; buf[w+1] = '\0';

        for (u_int i = 0; i < h; i++)
            printf("%s", buf);
        puts("");
    }
    
    return 0;
}