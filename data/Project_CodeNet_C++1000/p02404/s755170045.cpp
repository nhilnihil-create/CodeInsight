#include <iostream>

using namespace std;

int main(void)
{
    while (true) {
        u_int h, w;
        cin >> h >> w;
        if (!h && !w)
            break;
        
        char buf1[w+2], buf2[w+2];
        for (u_int i = 1; i < w-1; i++) {
            buf1[i] = '#';
            buf2[i] = '.';
        }
        buf1[0] = buf1[w-1] = buf2[0] = buf2[w-1] = '#';
        buf1[w] = buf2[w] = '\n';
        buf1[w+1] = buf2[w+1] = '\0';

        printf("%s", buf1);
        for (u_int i = 0; i < h-2; i++)
            printf("%s", buf2);
        printf("%s\n", buf1);
    }
    
    return 0;
}