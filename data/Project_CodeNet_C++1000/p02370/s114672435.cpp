#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

vector<int> edge[10010];
int h[10010];

int V;
int E;

int main()
{
    cin >> V;
    cin >> E;

    for(int i = 0;i < E;i++)
    {
        int s;
        int t;

        cin >> s >> t;

        edge[s].push_back(t);


        h[t]++;
    }

    stack<int> st;

    for(int i = 0;i < V;i++)
    {
        if(h[i] == 0) st.push(i);
    }

    vector<int> topolo;

    while(!st.empty())
    {
        int v = st.top();
        st.pop();

        topolo.push_back(v);

        for(int to : edge[v])
        {
            h[to]--;

            if(h[to] == 0)
            {
                st.push(to);
            }
        }
    }

    for(int ans : topolo)
    {
        cout << ans << endl;
    }

    return 0;


}
