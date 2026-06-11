#include <cstdio>
#include <iostream>
#define loop(var) for(int var=1;var<10;++var)

int main()
{
    loop(x) loop(y) printf("%dx%d=%d\n",x,y,x*y);
}