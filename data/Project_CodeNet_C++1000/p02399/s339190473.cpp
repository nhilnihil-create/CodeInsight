#include <iostream>
#include <cstdio>

int main(){

double f;
int x,y,d,r;

std::cin >> x >> y;

d = x/y;
r = x%y;
f = double(x)/double(y);

std::printf("%d %d %.5f", d, r, f);

return 0;
}