#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    int a,b,uncover;
    cin >> a >> b;
    uncover =  a - (2 * b);
    if(uncover < 0)
    {
        cout << "0";
    }
    else
    {
        cout << uncover;
    }
}
