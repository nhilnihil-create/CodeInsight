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
vector<ll>Ve;
set<ll>Se;
map<ll,ll>Mp;
deque<ll>De;
priority_queue<ll>Pe;
int main()
{
    // freopen("stand.in","r",stdin);
    // freopen("stand.out","w",stdout);
    AIA();

    string s;
    cin>>s;
    for(int i=0;i<s.size();i+=2){
        if(s[i]=='h'&&s[i+1]=='i'){
            continue;
        }
        else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
