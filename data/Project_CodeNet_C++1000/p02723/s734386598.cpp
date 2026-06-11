#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string S;
void input()
{
    cin>>S;
}

void solve()
{
    string ans="No";
    if(S[2]==S[3]&&S[4]==S[5]) ans="Yes";
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}