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
#define debug cout << "Test" << endl;

using namespace std;

void solve(){

	return;
}
 
int getLast(int n){
	
	while(n>=10){
		n/=10;
	}

	return n;

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<ii,int>ma;

	int n,cont=0,aux;
	cin >> n;

	for(int i=1;i<=n;i++){
		ma[make_pair(i%10,getLast(i))]++;
	}

	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
				cont+= ma[make_pair(i,j)] * ma[make_pair(j,i)];
	

		}
	}

	cout << cont << endl;

	return 0;
}