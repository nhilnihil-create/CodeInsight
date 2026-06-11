#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

string S;
void input()
{
    cin>>S;
}

void solve()
{
    string ans="Yes";
    int N=S.length();
    for(int i=0;i<N/2;++i){
        if(S[i]!=S[N-1-i]){
            ans="No"; break;
        }
    }
    for(int i=0;i<N/2;++i){
        if(S[i]!=S[N/2-1-i]){
            ans="No"; break;
        }
    }
    for(int i=0;i<N/2;++i){
        if(S[N/2+1+i]!=S[N-1-i]){
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