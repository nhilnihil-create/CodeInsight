#include <iostream>
using namespace std;

int main() {
    int r,s,t;
    cin>>r>>s>>t;
    if ((r<s)&&(s<t)){
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}
