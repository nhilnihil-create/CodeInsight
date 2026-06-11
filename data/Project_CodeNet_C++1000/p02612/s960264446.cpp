#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=10000;i+=1000)
    {
        if(i>=n) {cout<<i-n; break;}
    }

    return 0;
}
