#include <iostream>
using namespace std;
int main() {
    int l,r,d;
    cin>>l>>r>>d;
    int x=l/d;
    if(l%d==0) x--;
    int y=r/d;
    cout<<y-x;

    return 0;
}
