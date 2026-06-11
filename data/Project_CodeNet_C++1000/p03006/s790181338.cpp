#include <bits/stdc++.h> 
using namespace std;
typedef pair<int,int> P;

int main()
{
	int N;
	cin>>N;
	vector<P> cors;
	for( int i=0; i<N; i++ )
	{
		int x,y;
		cin>>x>>y;
		cors.push_back(P(x,y));
	}
	map<P,int> differs;
	int sum = 0;
	for( int i=0; i<N; i++ )
	{
		for( int j=i+1; j<N; j++ )
		{
			int dx = cors[j].first-cors[i].first, dy=cors[j].second-cors[i].second;
			differs[P(dx,dy)]++;;
			differs[P(-dx,-dy)]++;;
			if( sum < differs[P(dx,dy)] )
				sum = differs[P(dx,dy)];
		}
	}
	
	cout << N-sum << endl;
	return 0;
}