#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define debug cout << "Ok" << endl;

using namespace std;

void solve(){

	return;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	double aux;

	cin >> n;

	aux = n/3;

	if(n%3==2) aux+=0.6666666666666;
	if(n%3==1) aux+=0.3333333333333;

	cout << setprecision(10) << aux*aux*aux << endl;


	return 0;
}