#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long> pq;
int main()
{
	long long n ,m ,k;	
	while(cin>>n>>m)
	{
		long long sum = 0;
		for(int i=0 ;i<n ;i++) cin>>k ,pq.push(k);
		while(m--)
		{
			if(!pq.empty())
			{
				int t = pq.top();
				t /= 2;
				pq.pop();
				pq.push(t);
			}
		}
		while(!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}			
		cout<<sum<<'\n';			
	}
} 