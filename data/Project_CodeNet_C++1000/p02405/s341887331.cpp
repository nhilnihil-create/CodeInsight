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
        for (u_int i = 0; i < w; i+=2) {
            buf1[i] = buf2[i+1] = '#';
            buf1[i+1] = buf2[i] = '.';
        }
        buf1[w] = buf2[w] = '\n';
        buf1[w+1] = buf2[w+1] = '\0';

        for (u_int i = 0; i < h; i++)
            if (i % 2 == 0)
                printf("%s", buf1);
            else
                printf("%s", buf2);
        puts("");
    }
    return 0;
}