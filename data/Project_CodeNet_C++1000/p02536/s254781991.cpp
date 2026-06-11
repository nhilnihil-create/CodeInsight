#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
const double PI = 3.14159265358979323846;

void bfs(vector<int> &visit, vector<vector<int>> &G, int s, int &count)
{

    visit[s] = 1;

    for (int v : G[s])
    {

        if (visit[v] == 0)
        {

            visit[v] = 1;
            count++;
            bfs(visit, G, v,count);

          
        }
        
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(0));

    for (int i = 0; i < M; i++)
    {
        int A, B;

        cin >> A >> B;

        G[A - 1].push_back(B - 1);
        G[B - 1].push_back(A - 1);
    }
    vector<int> visit(N, 0);


    int count=0;

    int s_i = 0;

    int c=0;

    for(int i=0;i<N;i++){

        if(visit[i]==0){

            count++;
             bfs(visit, G, i,c);
        }
    
    }


    cout << count -1 << endl;

    return 0;
}