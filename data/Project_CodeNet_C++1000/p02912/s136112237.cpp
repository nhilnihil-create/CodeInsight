#include<bits/stdc++.h>
using namespace std;
int main()
{    priority_queue<unsigned long long int> q; 
	int  n,m;
    cin>>n>>m;
    unsigned long long int i, a[n];
    for(i=0;i<n;i++)
    { cin>>a[i]; q.push(a[i]);}
    unsigned long long int ans=0;
    while(m--)
    {
        long long int x=q.top();
    //cout<<x<<endl;
        q.pop();
        x=x/2;
        q.push(x);
        
    }
 
   while(!q.empty())
    {
        long long int x=q.top();
        //cout<<x<<endl;
        q.pop();
        ans+=x;}
    cout<<ans<<endl;
 
    
}
