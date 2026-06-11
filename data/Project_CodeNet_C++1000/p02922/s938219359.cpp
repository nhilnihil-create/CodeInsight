
#include <iostream>
using namespace std;

int main() {


    int a, b;

    cin>>a>>b;

    int c = 1;
    int i = 0;
    for(; c < b; i++)
        c = c + (a-1);


    cout<<i;


}
