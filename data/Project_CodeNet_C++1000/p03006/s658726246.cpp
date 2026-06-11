#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int X[MAX] , Y[MAX] , X2[MAX] , Y2[MAX] ;

int n ;

bool cmp(int a , int b)
{
	return X[a] < X[b] ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	set< pair<int , int> >s ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>X[i]>>Y[i] ;
		X2[i] = X[i] , Y2[i] = Y[i] ;
		s.insert({X[i] , Y[i]}) ;
	}
	vector<int>idx ;
	for(int i = 0 ; i < n ; ++i)
		idx.push_back(i) ;
	sort(idx.begin() , idx.end() , cmp) ;
	for(int i = 0 ; i < n ; ++i)
		X[i] = X2[idx[i]] , Y[i] = Y2[idx[i]] ;
	vector<int>vx , vy ;
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = i-1 ; j >= 0 ; --j)
			vx.push_back(X[i] - X[j]) , vy.push_back(Y[i] - Y[j]) ;
	}
	int ans = n ;
	for(auto &p : vx)
	{
		for(auto &q : vy)
		{
			if(p == 0 && q == 0)
				continue ;
			int cnt = 0 ;
			for(int i = 0 ; i < n ; ++i)
			{
				int a = X[i] - p , b = Y[i] - q ;
				if(s.find({a , b}) == s.end())
					cnt++ ;
			}
			ans = min(ans , cnt) ;
		}
	}
	return cout<<ans<<"\n" , 0 ;
}		