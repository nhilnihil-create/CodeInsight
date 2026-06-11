#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin>>a>>b;
    if (a>9 || b>9)
    {
        cout<<-1;
    }
    else if (a < 0 || b < 0)
    {
        cout<<-1;
    }
    else 
    {
        cout<<a*b;
    }
	return 0;
}