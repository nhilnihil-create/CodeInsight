#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool pairCompare(const P& p1, const P& p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

void step(vector<P>& d, vector< vector<int> >& edges, int node)
{
    queue<int> Q;
    Q.push(node);
    while(!Q.empty())
    {
        node = Q.front();
        Q.pop();
        for(int v : edges[node])
        {
            if(d[v].second < d[node].second + 1){
                d[v].second = d[node].second + 1;
                Q.push(v);
            }
        }
    }
}

void topological_sort(vector<P>& d, vector< vector<int> >& edges)
{
    int n = d.size();
    for(int i=0;i<n;++i)
    {
        if(d[i].second == 0) step(d, edges, i);
    }
    sort(d.begin(), d.end(), pairCompare);
}

int main()
{
    int N, M, s, t;
    cin >> N >> M;
    vector< vector<int> > edges(N);
    vector<P> d(N);
    for(int i=0;i<M;++i)
    {
        cin >> s >> t;
        edges[s].push_back(t);
    }
    for(int i=0;i<N;++i)
    {
        d[i] = make_pair(i, 0);
    }
    topological_sort(d, edges);
    for(int i=0;i<N;++i)
    {
        cout << d[i].first << endl;
    }
}

