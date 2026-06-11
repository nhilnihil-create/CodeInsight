#include <iostream>
using namespace std;

int main() {
    int d, k;
    cin>>k>>d;
    int s = 10-k;
    if (k >=10)
    {
        cout<<d;
    }
    else 
    {
        cout<<d+ 100*s;
    }
    
	return 0;
}