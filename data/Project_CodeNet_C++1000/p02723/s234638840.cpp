#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    string str; cin >> str;
    str[2]==str[3] && str[4]==str[5] ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
