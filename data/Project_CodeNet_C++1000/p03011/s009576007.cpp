#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x, y, z;
	cin>>x>>y>>z;
	cout<<min({x+y, x+z, y+z})<<endl;
}
