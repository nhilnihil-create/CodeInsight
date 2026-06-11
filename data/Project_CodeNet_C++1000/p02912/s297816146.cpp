#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin >>n>>m;
    std::vector<int> v(n);
    priority_queue<lli>pq;
    for (int i = 0; i < n; ++i)
    {
        /* code */cin>>v[i];
        pq.push(v[i]);
    }
    lli sum=0;
    while(m--){
        int temp=pq.top();
        pq.pop();
        pq.push(temp/2);
    }
    while(!pq.empty())
    {
        /* code */sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
    
    return 0;
}
