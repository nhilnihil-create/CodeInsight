#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int x;
    cin>>x;
    cout<<((~x)&0x1)<<endl;
    return 0;
}