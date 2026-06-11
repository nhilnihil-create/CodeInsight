/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,m=0,x=0;
    cin>>n>>m;
    priority_queue<int> pq;
    for(int i=0;i<n;++i)
    {
    	cin>>x;
    	pq.push(x);
    }
    while(m--)
    {
    	int tp=pq.top();pq.pop();
    	tp/=2;pq.push(tp);
    }
    lli sum=0ll;
    while(!pq.empty())
    {
    	sum+=pq.top();pq.pop();
    }
    cout<<sum<<endl;
}