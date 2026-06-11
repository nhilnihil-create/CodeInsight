#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
typedef long long ll;
int main()
{
    string s;
    cin>>s;

    if(s == "RRR")

        cout<< 3 <<endl;

    else if(s == "RRS"|| s =="SRR")

        cout << 2 <<endl;

    else if(s=="SSS")
        cout << 0 <<endl;

    else
        cout << 1 <<endl;

    return 0;
}