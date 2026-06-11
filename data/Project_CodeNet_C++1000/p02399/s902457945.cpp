#include <iostream>
#include <cstdio>
using namespace std;

int main(){
        int i,j;
        cin >> i >> j;

        printf("%d %d %lf\n", i/j, i%j, (double)i/(double)j);

        return 0;
}