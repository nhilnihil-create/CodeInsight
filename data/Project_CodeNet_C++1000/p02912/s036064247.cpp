#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int N,M;
    long long x,sum=0;
    priority_queue<int> q1;
    cin>>N>>M;
    for (int i=0;i<N;i++)
    {
        cin>>x;
        q1.push(x);
    }
    for (int i=0;i<M;i++)
    {
        int temp=q1.top();
        q1.pop();
        temp=temp/2;
        q1.push(temp);
    }
    while(!q1.empty())
    {
        sum+=q1.top();
        q1.pop();
    }
    cout<<sum<<endl;
}