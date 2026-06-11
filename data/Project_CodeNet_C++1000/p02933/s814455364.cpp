#include <iostream>
#include<map>

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int a;
    string s;
    cin >> a;
    cin >> s;
    if(a >= 3200) fin(s);
    else fin("red");
    return 0;
}