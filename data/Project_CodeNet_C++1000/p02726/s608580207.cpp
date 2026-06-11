#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Graph;

template <class type> void printVector(vector<type> vec){
    stringstream ss;
    for(ll i=0;i<vec.size();i++)
    {
        ss<<vec[i]<<" ";
    }
    cout<<ss.str()<<endl;
}


int main()
{
    ll N,X,Y;
    cin>>N>>X>>Y;X--;Y--;

    Graph dist(N,vector<ll>(N,-1));

    for(ll i=0;i<N;i++)
    {
        queue<ll> que;
        dist[i][i]=0;
        que.push(i);

        while(!que.empty())
        {
            ll v=que.front();
            que.pop();

            vector<int> adjacency;
            if (v>0) adjacency.push_back(v-1);
            if (v<N-1) adjacency.push_back(v+1);
            if (v==X) adjacency.push_back(Y);
            if (v==Y) adjacency.push_back(X);
            for (auto nv : adjacency) {
                if (dist[i][nv] == -1) {
                    dist[i][nv] = dist[i][v] + 1;
                    que.push(nv);
                }
            }
        }
    }


    vector<ll> res(N, 0);
    for (ll i=0;i<N;++i) {
        for (ll j=i+1;j<N;++j)res[dist[i][j]]++;
    }

    for(ll i=1;i<N;i++)
    {
        cout<<res[i]<<endl;
    }
}