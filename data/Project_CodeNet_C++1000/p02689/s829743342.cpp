#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int>height(N+1);
    map<int,queue<int>>conect;//行き先
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> height.at(i);
    }
    
    for(int i = 0 ; i < M ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        conect[a].push(b);
        conect[b].push(a);
    }

    // 良い展望台数　s
    int sum = 0;

    for(int i = 1 ; i <= N ; i++ )
    {
        bool good = true;
        while(!conect[i].empty())
        {

            if( height.at(conect[i].front()) >= height.at(i) )
            {
                good = false;
                break;
            }
            conect[i].pop();
        }
        if(good)
        {
            sum++;
        }
    }
    cout<<sum<<endl;

}