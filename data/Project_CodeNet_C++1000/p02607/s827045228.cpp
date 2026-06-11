
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
int n,i,count=0;
cin>>n;
int a[n];
for(i=1;i<=n;i++)
cin>>a[i];

for(i=1;i<=n;i++)
{
	if(i%2==1 && a[i]%2==1)
	count++;
}
cout<<count<<endl;
}