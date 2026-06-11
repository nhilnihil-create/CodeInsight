#include <iostream>
using namespace std;
int main() {

    int d,t,s;

    cin>>d>>t>>s;

    double req = d*1.0 / s;

    if(req <= t)
     cout<<"Yes\n";
    else
     cout<<"No\n";
}
