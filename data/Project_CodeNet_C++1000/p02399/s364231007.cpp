#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    
    cout << a/b << ' ' << a%b << ' ';
    printf("%.8f\n",(double)a/(double)b);
    
    return 0;
}
