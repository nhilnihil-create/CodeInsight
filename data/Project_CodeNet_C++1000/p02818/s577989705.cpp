#include <iostream>
using namespace std;

int main() {
    long long a, b, k;
    cin>>a>>b>>k;
    long d= a+b;
    if (a > k)
    {
        cout<<a-k<<" "<<b;
    }
    else if (d>=k)
    {
        cout<<0<<" "<<d-k;
    }
    else 
    {
        cout<<0<<" "<<0;
    }
    
    
	return 0;
}