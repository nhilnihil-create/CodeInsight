#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

#define ull unsigned long long
#define ll long long
#define rep(i,j) for(int i=0;i<j;++i)
#define loop(i,a,j) for(int i=a;i<j;++i)
#define mpi(it,table,T,E) for(map<T,E>::iterator it = table.begin();it!=table.end();++it)
#define PI 3.141592654
/*
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
*/
#define N 5005

bool visited[N][N];
int data[N];

int solve(int i,int j,int sum){
	if( i == j) return sum;
	if(visited[i][j])return sum;
	
	int a = max(sum,solve(i+1,j,sum-data[i]));
	int b = max(sum,solve(i,j-1,sum-data[j]));

	visited[i][j] = true;
	return max(a,b);
}


int main(){
	int n;
	while(scanf("%d",&n),n){
		memset(visited,0,sizeof(visited));
		int sum = 0;
		rep(i,n){
			scanf("%d",&data[i]);
			sum += data[i];
		}
		sum = solve(0,n-1,sum);
		printf("%d\n",sum);	
	}
	return 0;
}