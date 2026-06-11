#include <iostream>

using namespace std;
int c[10001],s;

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>c[i];
    for (int i=1; i<=n; i+=2)
        if (c[i]%2==1)
            s++;
    cout<<s;
    return 0;
}