#include<bits/stdc++.h>
using namespace std;
queue<long long> q;
vector<long long> ans;
long long n,m,i,j,k,l,p,o,s;
int main()
{
    for(i=1;i<=9;i++)
    q.push(i);
    while(ans.size()<111111)
    {
        n=q.front();
        ans.push_back(n);
        q.pop();
        m=n%10;
        if(m>0) q.push(n*10+m-1);
        if(m<9) q.push(n*10+m+1);
        q.push(n*10+m);
    }
    sort(ans.begin(),ans.end());
	cin>>k;
    cout<<ans[k-1];
    return 0;
}