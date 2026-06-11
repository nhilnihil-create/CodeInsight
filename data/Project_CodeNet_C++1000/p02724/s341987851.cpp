#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int num = n%500;
    n=n/500;
    n=n*1000;
    num=num/5;
    n=n+5*num;
    cout<<n<<endl;

    return 0;
}