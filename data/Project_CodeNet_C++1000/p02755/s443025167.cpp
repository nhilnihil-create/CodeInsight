#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int A,B;
void input()
{
    cin>>A>>B;
}

void solve()
{
    int ans=B*10;
    for(int i=0;i<10;++i){
        int tmp=(ans+i)*0.08;
        if(tmp==A){
            cout<<ans+i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}