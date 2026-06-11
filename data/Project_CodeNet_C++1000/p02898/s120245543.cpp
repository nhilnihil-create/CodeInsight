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
ll int N,K;
cin >> N >> K;

ll int counter = 0;
vector<ll int> h(N);
rep(i,N){
	cin >> h[i];
	if(h[i]>=K){
		counter+=1;
}
}

cout << counter;










	return 0;

}

