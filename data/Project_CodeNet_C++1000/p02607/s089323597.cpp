#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
int n,cnt=0;
cin>>n;
vector<int>a(n+1);
for(int i=1;i<=n;i++)
	cin>>a[i];
for(int i=1;i<=n;i++)
{
	if((i&1)&&(a[i]&1))
		cnt++;
}
cout<<cnt;
  return 0;
}


