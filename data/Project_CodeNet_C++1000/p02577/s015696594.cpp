#include <iostream>
using namespace std;

main() {
    string s;
    cin>>s;
    int sum=0;
    for (char c:s) {
        sum+=c-'0';
    }
    cout<<(sum%9?"No":"Yes")<<endl;
}