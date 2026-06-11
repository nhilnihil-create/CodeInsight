#include<iostream>
#include<cstdio>

using namespace std;

int ball[11];
int a[11],b[11];
bool ans;

bool dfs(int i,int p,int q)
{
	 if(ball[i] < a[p] && ball[i] < b[q]) return false;
	 if(i == 9) return true;
	 bool tmp = false;
	 if(a[p] < ball[i])
	 {
		 a[p+1] = ball[i];
		 tmp = (tmp || dfs(i+1,p+1,q));
	 }
	 if(b[q] < ball[i])
	 {
	 	b[q+1] = ball[i];
		 tmp = (tmp || dfs(i+1,p,q+1));
	 }
	 return tmp;
}


int main ()
{
	int n;
	cin >> n;
	for(int i= 0;i<n;i++)
	{
		a[0]=0,b[0]=0;
		for(int j = 0;j < 10;j++) cin >> ball[j];
		a[1] = ball[0];
		ans = dfs(1,0,0);
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}