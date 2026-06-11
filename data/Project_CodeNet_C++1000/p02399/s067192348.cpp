#include <cstdio>
#include <iostream>

using namespace std;

int a, b;

int main(){
    cin >> a >> b;
    printf("%d %d %.5f\n", a/b, a%b, (double)a/(double)b);
    
    return 0;
}
