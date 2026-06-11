#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
int main()
{
    int a, b;
    cin >> a >> b;
    if ( (a == 1 && b == 2) ||(a == 2 && b == 1)) cout << 3 << endl;
    else if((a== 2 && b == 3)||(a== 3&& b==2))cout << 1 << endl;
    else cout << 2 << endl;
}
