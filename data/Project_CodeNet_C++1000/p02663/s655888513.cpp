#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 309;
const int mod = 1e9 + 7;
typedef long long int ll;	

int main () {
	int a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	cout<< (c-a)*60 + (d-b) - k;
}
