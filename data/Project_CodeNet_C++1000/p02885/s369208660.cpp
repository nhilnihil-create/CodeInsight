#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cin>>a>>b;
    int c = a - 2*b;
    if (c<0)
    {
        cout<<0;
    }
    else 
    {
        cout<<c;
    }
	return 0;
}