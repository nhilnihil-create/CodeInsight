#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int N;
void input()
{
    cin>>N;
}

void solve()
{
    ll ans=0;
    for(int i=1;i<=N;++i){
        if(i%3==0 || i%5==0) continue;
        ans+=i;
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