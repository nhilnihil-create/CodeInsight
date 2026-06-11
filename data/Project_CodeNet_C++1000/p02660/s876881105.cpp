#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const double PI=acos(-1.0);

ll N;
void input()
{
    cin>>N;
}

void solve()
{
    if(N==1){
        cout<<0<<endl;
        return;
    }

    map<ll,int> M;
    while(N%2==0){
        N/=2; M[2ll]++;
    }
    for(ll i=3;i*i<=N;i+=2){
        while(N%i==0){
            N/=i; M[i]++;
        }
    }
    if(N!=1) M[N]++;

    ll ans=0;
    for(auto m:M){
        // cout<<m.first<<" "<<m.second<<endl;
        int add=0;
        for(int i=1;;++i){
            add+=i;
            if(m.second>=add) ++ans;
            else break;
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