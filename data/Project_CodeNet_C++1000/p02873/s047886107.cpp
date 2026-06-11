#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define debug printf(" I am here\n");

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N = 5e5+10, mod=1e9+7;
int t, n, m; 
int a[N];
bool st[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	
	int cnt = 0, d;
	for(int i = 0 ; i < s.size() ; i ++)
	{
		if(s[i] == '>')
		{
			if(cnt == 0)
				d = i;
			cnt ++;
		}
		else
		{
			if(cnt != 0)
				a[d] = cnt;
			cnt = 0;
		}
	}
	if(cnt != 0)
		a[d] = cnt;	
	
	// < >>> << > <<<<< >>> <
	int j;
	bool flag = false;
	for(int i = 0 ; i < s.size() ; i ++)
	{
		if(s[i] == '>' && s[i+1] == '<')
			a[i+1] = 0, flag = false;
		else if(s[i] == '<' && a[i+1] <= a[i])
			a[i+1] = a[i] + 1, flag = false;
		else if(s[i] == '>')
		{
			if(!flag)
			{
				for(j = i ; s[j] == '>' && j < s.size(); j ++);
				j = j - i;				
			}
			a[i+1] = j - 1;	
			j --;
			flag = true;		
		}
	
	}
	/*cout << a[0];
	for(int i = 0 ; i < s.size() ; i ++)
		cout << s[i] << a[i+1];*/
	long long sum = 0;
	for(int i = 0 ; i <= s.size() ; i ++)
		sum += a[i];
	cout << sum << endl;
}