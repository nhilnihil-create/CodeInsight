#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a,b;
    cin >> a >> b;
    
    printf("%d %d %.5f",a/b,a%b,(double)a/b);
    
    return 0;
}