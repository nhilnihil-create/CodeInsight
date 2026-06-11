#include<bits/stdc++.h>
using namespace std;

// #define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define w(x)  int x; cin>>x; while(x--)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"

#define ll  long long
#define all(c) (c).begin(),(c).end()
#define nl "\n"

typedef vector<int> vl;
typedef vector< vl > vvl;
typedef pair< int,int> pll;typedef map< int,int> mll;


void c_p_c()
{
#ifndef ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int main() {
	

	c_p_c();
	

	int n,o=1;
	cin>>n;
	int a,b;
	
	cin>>a>>b;
	for (int i = a; i <= b; ++i)
	{
		if(i%n==0){
			cout<<"OK";
			o=0;
			break;
			
		}

	}
	if(o==1)
	cout<<"NG";













	return 0;

}
