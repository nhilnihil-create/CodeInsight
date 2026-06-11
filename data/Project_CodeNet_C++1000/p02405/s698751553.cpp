#include <iostream>
using namespace std;
int main() {
    int H,W,i,j;
    while (cin>>H>>W && (H!=0 || W!=0)) {
        for (i=0;i<H;i++) {
            for (j=0;j<W;j++) {
                cout << ((i+j)%2==0?'#':'.');
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}