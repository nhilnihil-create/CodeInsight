#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,x,s=0;
    priority_queue <int,vector <int>,greater <int> >pq;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>x;
        pq.push(x);
    }
     for(i=0;i<k;i++)
     {
         s+=pq.top();
         pq.pop();
     }
    cout << s << endl;
    return 0;
}