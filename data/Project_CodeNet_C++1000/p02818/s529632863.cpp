#include<iostream>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main()
{
	FIO;
	LL a, b, k; cin>>a>>b>>k;
	if(a==k) { cout<<0<<" "<<b<<endl; return 0; }
	else if(a>k) { cout<<a-k<<" "<<b<<endl; return 0; }
	else k-=a, a=0;

	if(b==k) cout<<a<<" "<<0<<endl;
	else if(b>k) cout<<a<<" "<<b-k<<endl;
	else cout<<0<<" "<<0<<"\n";
}