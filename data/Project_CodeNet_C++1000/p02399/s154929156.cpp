#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << a/b << " " << a%b << " " << endl;
    printf("%.8lf\n", (double)a/b);
    return 0;
}
