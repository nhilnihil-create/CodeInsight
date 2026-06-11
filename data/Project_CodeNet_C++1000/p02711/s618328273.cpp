#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
void input()
{
    cin>>N;
}

void solve()
{
    string ans="No";
    while(N>0){
        if(N%10==7){
            ans="Yes"; break;
        }
        N/=10;
    }
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