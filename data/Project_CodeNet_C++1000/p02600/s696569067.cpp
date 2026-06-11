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
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x;
	cin>>x;
	cout<<10-(x/200);
	return 0; 
	
}
