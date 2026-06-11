#include <iostream>
using namespace std;

main() {
    string s;
    cin>>s;
    int sum=0;
    for (char c:s) {
        sum=(sum+(int)(c-'0'))%9;
    }
    if (sum==0) {
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }
}