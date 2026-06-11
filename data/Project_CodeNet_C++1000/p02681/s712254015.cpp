#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

string S,T;
void input()
{
    cin>>S>>T;
}

void solve()
{
    string ans="Yes";
    for(int i=0;i<S.length();++i){
        if(S[i]!=T[i]){
            ans="No"; break;
        }
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