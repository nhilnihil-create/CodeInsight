#include <bits/stdc++.h>
#define pb push_back
#define ff first;
#define ss second;
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double pi = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin >> a >> b; 
	int sum = a*500;
	if(sum>=b){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	
	return 0;
}

