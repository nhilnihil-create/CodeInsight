#include<cstdio>
#include<queue>
int n;
std::priority_queue<double> pq;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		double x;
		scanf("%lf",&x);
		pq.push(-x);
	}
	while (pq.size()>1)
	{
		double x=-pq.top();pq.pop();
	    double y=-pq.top();pq.pop();
	    pq.push(-(x+y)/2);
	}
	printf("%lf\n",-pq.top());
	return 0;
}