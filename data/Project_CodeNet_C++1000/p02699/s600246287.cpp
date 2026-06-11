#include<iostream>
#include<math.h>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main()
{
	int s, w; cin>>s>>w;
	if(s>w) cout<<"safe\n";
	else cout<<"unsafe\n";
}