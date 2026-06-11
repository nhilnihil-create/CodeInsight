#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const double PI=acos(-1.0);

int k;
void input()
{
    cin>>k;   
}

void solve()
{
    vll table; queue<ll> q;
    for(int i=1;i<10;++i) {table.emplace_back(i);q.push(i);}
    int times=100000;
    while(times>0){
        ll tmp=q.front(); q.pop();
        if(tmp%10==0){
            table.emplace_back(tmp*10);table.emplace_back(tmp*10+1);
            q.push(tmp*10);q.push(tmp*10+1);
        }
        else if(tmp%10==9){
            table.emplace_back(tmp*10+tmp%10-1);table.emplace_back(tmp*10+tmp%10);
            q.push(tmp*10+tmp%10-1);q.push(tmp*10+tmp%10);
        } else {
            table.emplace_back(tmp*10+tmp%10-1);
            table.emplace_back(tmp*10+tmp%10);
            table.emplace_back(tmp*10+tmp%10+1);
            q.push(tmp*10+tmp%10-1);
            q.push(tmp*10+tmp%10);
            q.push(tmp*10+tmp%10+1);
        }
        --times;
    }
    sort(table.begin(),table.end());
    // for(int i=0;i<100;++i) cout<<table[i]<<" ";
    // cout<<endl;
    cout<<table[k-1]<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}