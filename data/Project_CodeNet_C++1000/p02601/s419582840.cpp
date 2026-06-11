#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first 
#define ss second  
typedef pair<int,int> pp;
bool com(pp x,pp y){
    return x.ff<y.ff;
} 
int N=1e5+9;
bool f(int a,int b,int c,int k){
    if(b>a&&c>b) return 1;
    if(k<=0) return 0;
    return f(a*2,b,c,k-1)||f(a,b,c*2,k-1)||f(a,b*2,c,k-1);
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,k;
	cin>>a>>b>>c;
	cin>>k;
	if(f(a,b,c,k)) cout<<"Yes";
	else cout<<"No";
	return 0; 
	
}
