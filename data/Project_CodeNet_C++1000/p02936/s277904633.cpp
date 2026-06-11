#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int> > graph(N, vector<int>(0));
vector<vector<int> > children(N, vector<int>(0));
vector<long long> cnt(N, 0);
vector<bool> seen(N, false);

void child(int id, int parent)
{
    //cout << "child呼び出し: " << id << endl;
    for (int i=0; i<graph[id].size(); i++)
    {
        if (graph[id][i]!=parent)
        {
            children[id].push_back(graph[id][i]);
            child(graph[id][i], id);
        }
    }
}

void flow(int id)
{
    if (!seen[id])
    {
        seen[id] = true;
        for (int i=0; i<children[id].size(); i++)
        {
            int child = children[id][i];
            cnt[child] += cnt[id];
            flow(child);
        }
    }
}

int main()
{
    int Q;
    cin >> N >> Q;
    graph = vector<vector<int> > (N, vector<int>(0));
    children = vector<vector<int> > (N, vector<int>(0));
    cnt = vector<long long> (N, 0);
    seen = vector<bool> (N, false);
    for (int i=0; i<N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    child(0, -1);
    /*
    for (int i=0; i<N; i++)
    {
        cout << i <<"の子供: ";
        for (int j=0; j<children[i].size(); j++)
        {
            cout << children[i][j] << " ";
        }
        cout << endl;
    }
    */
    seen = vector<bool> (N, false);

    for (int i=0; i<Q; i++)
    {
        seen = vector<bool> (N, false);
        int p, x;
        cin >> p >> x;
        cnt[p-1] += x;
    }
    flow(0);
    for (int i=0; i<N; i++) cout << cnt[i] << " ";
    cout << endl;
}