#include <iostream>
using namespace std;

int main() {
    int p,q,r;
    cin>>p>>q>>r;
    int sum;
    sum = p+q+r - max(p,max(q,r));
    cout<<sum<<endl;
}
