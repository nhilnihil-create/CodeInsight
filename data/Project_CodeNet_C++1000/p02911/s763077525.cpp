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

ll int N,K,Q;
cin >> N >> K >> Q;
vector<ll int > A(Q);
map < ll int,ll int >counter;

rep(i,Q){
	cin >> A[i];
	counter[A[i]-1] += 1;
}

rep(i,N){
	if(K - Q + counter[i] >0){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}














	return 0;

}

