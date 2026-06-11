#include <iostream>
using namespace std;
int main() {
    short t,n,count = 0;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        if (i % 2 == 1 && n % 2 == 1)
            count++;
    }
    cout<<count;
    return 0;
}