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
	
	long long int n,cont=1,aux,l;
	queue<long long int>q;
	for(int i=1;i<10;i++){
		q.push(i);
	}

	cin >> n;

	while(true){
		aux = q.front();
		q.pop();
		if(n==cont){
			cout << aux << endl;
			return 0;
		}
		l = aux%10;
		aux*=10;
		if(l!=0){
			q.push(aux+l-1);
		}
		q.push(aux+l);
		if(l!=9){
			q.push(aux+l+1);
		}
		cont++;
	}
	return 0;
}