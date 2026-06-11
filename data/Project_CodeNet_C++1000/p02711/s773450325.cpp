#include <iostream>

using namespace std;
int a,b;
int main()
{
    cin>>a;
    while(a>0){
        b=a%10;
        if (b==7) {
            cout<<"Yes";
            return 0;
        }
        a/=10;
    }
    cout<<"No";

    return 0;
}
