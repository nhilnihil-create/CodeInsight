#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
int main(){ 
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	if(a/n!=b/n||a%n==0||b%n==0)
		cout<<"OK\n";
	else
		cout<<"NG\n";
}

