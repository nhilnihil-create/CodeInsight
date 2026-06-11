#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
    int a,b;
    cin >> a >> b;
    if((b-a) % 2 == 0)
        cout << a+(b-a)/2;
    else
        cout  << "IMPOSSIBLE";

}
