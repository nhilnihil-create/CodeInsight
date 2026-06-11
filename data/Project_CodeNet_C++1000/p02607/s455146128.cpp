#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n,c(0),x;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>x;
        if (i%2==1 && x%2==1) c++;
    }
    cout<<c;
}