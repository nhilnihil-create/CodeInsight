#include<bits/stdc++.h>
#define ll 	long long
#define pb push_back
#define mp make_pair
using namespace std;

int main() {

int k; cin>>k;
int a,b; cin>>a>>b;

int dd= 0;

for(int i=a;i<=b;i++)
{
	if(i%k==0)
	{
		dd=1;
		break;
	}
}
if(dd==0)
cout<<"NG\n";
else cout<<"OK\n";
    return 0;
}