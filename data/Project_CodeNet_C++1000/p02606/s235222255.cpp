#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
int a,b,d,cnt=0;
cin>>a>>b>>d;
for(int i=a;i<=b;i++)
	if(!(i%d))
		cnt++;
	cout<<cnt<<endl;
  return 0;
}

