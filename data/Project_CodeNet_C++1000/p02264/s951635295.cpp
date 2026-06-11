#include <string>
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n,q,times=0;
pair<string,int> process1;
queue<pair <string,int> > Q;
void solve()
{
    while(!Q.empty())
    {
        process1=Q.front();Q.pop();
        if(process1.second<=q)
        {
            times+=process1.second;
            cout<<process1.first<<" "<<times<<endl;
        }
        else
        {
            times+=q;
            process1.second-=q;
            Q.push(process1);
        }
    }
}
int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>process1.first>>process1.second;
        Q.push(process1);
    }
    solve();
    return 0;
}
