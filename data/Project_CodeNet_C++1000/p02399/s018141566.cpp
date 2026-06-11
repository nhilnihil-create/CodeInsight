#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    int a, b;
    cin>>a>>b;
    cout<<a/b<<' '<<a%b<<' '<<(double)a/b<<'\n';
    return 0;
}