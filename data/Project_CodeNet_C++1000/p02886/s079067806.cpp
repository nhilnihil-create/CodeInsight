#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>

#define rep(i,p) for(long long int i=0;i<p;i++)
#define reep(i,p) for(long long int i=1;i<=p;i++)
#define ll long long

using namespace std;

int main(){


ll int N;
cin >> N;

vector<ll int> d(N);
rep(i,N){
	cin >> d[i];
}

ll int wa = 0;
rep(i,N){
	for(ll int j=i+1;j<N;j++){
		wa += d[i]*d[j];
	}
}
cout << wa;











	return 0;

}

