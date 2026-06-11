#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int m , n ,f[200005] , l ,sum, x,y,book[200005];
int df(int u)
{
	 if(f[u] ==u ) return u;
	 else 
	 {
	 	 f[u] = df(f[u]);
	 	 return f[u];
	 }
}
void getf(int t1 ,int t2)
{
	int k1 = df(t1) ;
	int k2 = df(t2) ;
	
    f[k2] = k1 ;

}
int main()
{   
    cin >> n >> m ;
	for(int i = 1 ; i <= n; i++) f[i] = i ;
	for(int i = 1; i <= m; i++)
	{ 
	   cin >> x >> y ;
	   getf(x,y);
	}
	
	for(int i = 1 ; i <= n; i++) df(i);
	
	for(int i = 1 ; i <= n; i++)  book[f[i]]++;
	
	for(int i = 1 ; i <= n; i++)
	sum = max(sum,book[i]);
	
	cout << sum ;
	return 0 ; 
}