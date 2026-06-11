#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,a,b,c;
  	cin>>x>>y>>a>>b>>c;
  	priority_queue<int>r;
  	priority_queue<int>g;
  	priority_queue<int>C;
  	for(int i=0;i<a;i++)
    {
      int X;
      cin>>X;
      r.push(X);
    }
  	for(int i=0;i<b;i++)
    {
      int X;
      cin>>X;
      g.push(X);
    }
  	for(int i=0;i<c;i++)
    {
      int X;
      cin>>X;
      C.push(X);
    }
  	//cout<<r.size()<<endl;
  	priority_queue<int,vector<int>,greater<int>>A;
  	while(x--)
    {
      A.push(r.top());
      r.pop();
    }
  	while(y--)
    {
      A.push(g.top());
      g.pop();
    }
  	while(A.top()<=C.top())
    {
      A.pop();
      A.push(C.top());
      C.pop();
      if(C.empty())break;
    }
  	long long ans=0;
  	
  	while(!A.empty())
    {
      ans+=A.top();
      A.pop();
    }
  	cout<<ans<<endl;
	return 0;
}
  