#include<iostream>
using namespace std;
int main()
{
    string x;
    cin>>x;
    if(x[0]=='S') cout<< "Cloudy\n";
    else if(x[0]=='C') cout<< "Rainy\n";
    else cout<< "Sunny\n";

    return 0;
}
