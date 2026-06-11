#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
//:/
#define pb emplace_back
#define mp make_pair
#define nt _ll128
#define ld long double
long double PI =3.14159265358979323846;
using ll = long long;



const ll modo=1e9+7;
const ll inf=1e17;
const ll ms=(2e6)+5;


ll ar[ms];
ll cost[ms];
ll br[ms];


int main()
{

    int n,m;
    cin>>n>>m;
    priority_queue<int> q;
    int e;

    while(n--)
    {
        cin>>e;
        q.push(e);
    }

    while(m--)
    {
        e=q.top();
        q.pop();
        q.push(e/2);
    }
    ll ans=0;
    while(!q.empty())
    {
        ans+=q.top();
        q.pop();
    }
    cout<<ans;


    return 0;
}