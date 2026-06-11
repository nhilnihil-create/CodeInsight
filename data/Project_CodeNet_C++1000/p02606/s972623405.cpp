
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
int l,r,d,count;
cin>>l>>r>>d;
int i;
count=0;
for(i=l;i<=r;i++)
{
	if(i%d==0)
	count++;
}
cout<<count<<endl;
}