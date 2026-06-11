#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin>>a>>b;
    int d= a+b;
    if (d % 2 == 0)
    {
        cout<<d/2;
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    
}