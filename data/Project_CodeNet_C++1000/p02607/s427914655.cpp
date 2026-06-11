#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n , t=0;
    cin>>n;
    int *a = new int[n];
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
        if(a[i]%2 != 0 && i%2 ==0 )
            t++;
    }
    cout<<t;
    return 0;
}
