#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> pena(N,0);
    vector<ll> ok(N,0);
    ll res1=0;
    ll res2=0;
    for (int i = 0; i < M; i++)
    {
        ll p;
        string status;
        cin >> p >> status;--p;
        if(status=="AC"){
            if(!ok[p]){
                ++res1;res2+=pena[p];ok[p]=true;
            }
        }
        else pena[p]++;
    }
    cout<<res1<<" "<<res2;
    return 0;
}
