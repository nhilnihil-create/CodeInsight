#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int dx[] = {-1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1};
const int dy[] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1};
#define N 8010000
#define TC int t;cin>>t;while(t--)
#define all(x) (x).begin(),(x).end()
void AIA(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
/*
             __               _____________                __                        _____________              __                ___        ___       ___________________________     ____        ____
            /\ \             |_____   _____|              /\ \                      |             |            /\ \              |   |      |   |     |                           |    \   \      /   /
           / /\ \                  | |                   / /\ \                     |   __________|           / /\ \             |   |      |   |     |      _____      _____     |     \   \    /   /
          / /  \ \                 | |                  / /  \ \                    |  |                     / /  \ \            |   |      |   |     |     |     |    |     |    |      \   \  /   /
         / /    \ \                | |                 / /    \ \                   |  |                    / /    \ \           |   |      |   |     |     |     |    |     |    |       \   \/   /
        / /      \ \               | |                / /      \ \                  |  |______             / /      \ \          |   |______|   |     |     |     |    |     |    |        \      /
       / /        \ \              | |               / /        \ \                 |         |           / /        \ \         |              |     |     |     |    |     |    |         \    /
      / /          \ \             | |              / /          \ \                |   ______|          / /          \ \        |    ______    |     |     |     |    |     |    |          |  |
     / /============\ \            | |             / /============\ \               |  |                / /============\ \       |   |      |   |     |     |     |    |     |    |          |  |
    / /==============\ \           | |            / /==============\ \              |  |               / /==============\ \      |   |      |   |     |     |     |    |     |    |          |  |
   / /                \ \          | |           / /                \ \             |  |              / /                \ \     |   |      |   |     |     |     |    |     |    |          |  |
  / /                  \ \    _____| |_____     / /                  \ \            |  |             / /                  \ \    |   |      |   |     |     |     |    |     |    |          |  |
 /_/                    \_\  |_____________|   /_/                    \_\ _________ |__|            /_/                    \_\   |___|      |___|     |_____|     |____|     |____|          |__|

                                                                      <<<<<<<<<<< NEVER GIVE UP !! >>>>>>>>>>>
                                                                    <<<<<<<< YOU CAN DO IT IF YOU WANT !! >>>>>>>>
                                                                     <<<<<<<<< BELIEVE IN YOURSELF !! >>>>>>>>>
*/
struct dis{
ll x;
ll y;
ll c;
};
set<ll>Se;
map<ll,ll>Mp;
deque<ll>De;
priority_queue<ll>Pe;
int main()
{
    // freopen("stand.in","r",stdin);
    // freopen("stand.out","w",stdout);
    AIA();
    int a , b , m;
    cin>>a>>b>>m;
    vector<ll>A(a+1);
    vector<ll>B(b+1);
    vector<dis>M(m+1);
    ll ma=LONG_MAX;
    for(int i=1;i<=a;i++){
        cin>>A[i];
        if(A[i]<ma){
            ma=A[i];
        }
    }
    ll mb=LONG_MAX;
    for(int i=1;i<=b;i++){
        cin>>B[i];
        if(mb>B[i]){
            mb=B[i];
        }
    }
    ll cnt = LONG_MAX;
    for(int i=0;i<m;i++){
        cin>>M[i].x>>M[i].y>>M[i].c;
        cnt = min(cnt , A[M[i].x]+B[M[i].y]-M[i].c);
    }
    cout<<min(cnt,mb+ma);
    return 0;
}








