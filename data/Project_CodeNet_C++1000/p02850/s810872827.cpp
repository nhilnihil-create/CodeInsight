#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
struct edge {int from, to, color; };
vector<edge> G[100010];


int cnt[100010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;

    map<P, int> mp;    
    edge es[N-1];

    rep(i, N-1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge e;
        e.from=a;
        e.to=b; 
        e.color=0;
        cnt[a]++; cnt[b]++;

        es[i]=e;
        G[e.from].push_back(e);
        G[e.to].push_back(e);
    }

    queue<int> que;  //for next vertex 
    que.push(0);

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        bool used[N];
        FILL0(used);
        int cur=1; 


        rep(i, G[v].size())
        {
            if(mp[P(G[v][i].from, G[v][i].to)]!=0)
            {
                used[mp[P(G[v][i].from, G[v][i].to)]]=true;
            }
        }

        rep(i, G[v].size())
        {
            if(mp[P(G[v][i].from, G[v][i].to)]==0)
            {
                while(used[cur])
                {
                    cur++;
                }

                if(!used[cur])
                {
                    G[v][i].color=cur;
                    mp[P(G[v][i].from, G[v][i].to)]=G[v][i].color;
                }
                
                cur++;                
            }

            if(G[v][i].to!=v)
            {
                que.push(G[v][i].to);
            }
        }
    }

    int MAX_C = 0;
    rep(i, N)
    {
        if(cnt[i]>MAX_C)
        {
            MAX_C=cnt[i];
        }
    }

    cout << MAX_C << endl;

    rep(i, N-1)
    {
        cout << mp[P(es[i].from,es[i].to)] << endl;
    }


    return 0;
}
 

//cout << setprecision(13);
//next_permutation();
//__gcd();
//reverse();
//set ,tuple ,pair;
//bitset
//vector.find

