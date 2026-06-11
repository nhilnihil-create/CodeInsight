#include <iostream>
#include <string>
using namespace std;
int main() {
    int count=0;

    int n ;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int k ;
        cin>>k;
        if(i%2==1 && k%2==1)
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}