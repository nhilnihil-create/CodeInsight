#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    if (n%2==0) {
        int ans=n/2;
        cout<<ans<<endl;
    }
    else {
        int ans=n/2+1;
        cout<<ans<<endl;
    }
    return 0;
}