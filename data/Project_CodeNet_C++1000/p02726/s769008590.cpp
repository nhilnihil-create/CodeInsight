#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

void ALLOUT_NUMBER(vector<ll> V)
{
    ll N = V.size();
    for(ll i=0;i<N;i++)
    {
        cout << V[i];
        if(i<N-1) cout << ' ';
    }
    cout << endl;
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

class Node
{
    public:
    ll number;
    vector<ll> nexts;
    ll Dis = 0; // 他の頂点との最短距離
    bool seen = false;
};

void ALLIN_NODES(vector<Node>& nodes,ll N, ll X, ll Y)
{
    for(ll i=0;i<N;i++)
    {
        nodes[i].number = i;
    }
    for(ll i=0;i<N;i++)
    {
        if(i==0)
        {
            nodes[i].nexts.push_back(i+1);
        }
        else if(i==N-1)
        {
            nodes[i].nexts.push_back(i-1);
        }
        else
        {
            nodes[i].nexts.push_back(i-1);
            nodes[i].nexts.push_back(i+1);
        }
    }
    nodes[X-1].nexts.push_back(Y-1);
    nodes[Y-1].nexts.push_back(X-1);
}

void ALLOUT_NODES(vector<Node> nodes)
{
    for(auto x : nodes)
    {
        cout << '(' << x.number+1 << ',' << x.Dis << "), ";
    }
    cout << endl;
}

void BFS(vector<Node> nodes, Node root, map<ll,ll>& all_diss)
{
    queue<Node> bfs;
    nodes[root.number].seen = true;
    bfs.push(nodes[root.number]);

    while(!bfs.empty())
    {
        Node front_copy = bfs.front();
        bfs.pop();
        for(auto x : front_copy.nexts)
        {
            if(!nodes[x].seen)
            {
                nodes[x].Dis = front_copy.Dis+1;
                nodes[x].seen = true;
                bfs.push(nodes[x]);
            }
        }
    }

    for(auto x : nodes)
    {
        all_diss[x.Dis]++;
    }
}

int main()
{
    ll N,X,Y;
    cin >> N >> X >> Y;

    vector<Node> nodes(N);
    ALLIN_NODES(nodes,N,X,Y);

    map<ll,ll> all_diss;
    for(auto x : nodes)
    {
        BFS(nodes,x,all_diss);
    }

    for(ll i=1;i<=N-1;i++)
    {
        OUT0(all_diss[i]/2);
    }

    return 0;
}