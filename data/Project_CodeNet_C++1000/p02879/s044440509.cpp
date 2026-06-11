#include <bits/stdc++.h>
using namespace std;
#define	fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(n,arr)  for(int i=0;i<n;i++)cin>>arr[i]; // 0 => n
#define	pi 3.14159265358979323846
#define	endl "\n"
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+5 , oo=0x3f3f3f3f , mod=1e9+7;

int main(){
	int a,b;
	cin>>a>>b;
	if(a<=9 && b<=9)
		cout<<a*b;
	else
		cout<<-1;
	return 0;
}