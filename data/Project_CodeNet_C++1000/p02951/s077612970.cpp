#include<iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int res = c-(a-b);
    if(res<0) { cout << 0 << endl; }
    else { cout << res << endl;}
    return 0;
}