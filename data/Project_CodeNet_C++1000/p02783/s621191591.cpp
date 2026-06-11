#include <iostream>
using namespace std;

int main() {
    int H, A, i;
    cin>>H>>A;
    for (i=0; H>0; i++){
    H-=A;
    };
    cout<<i;

    return 0;
    }

