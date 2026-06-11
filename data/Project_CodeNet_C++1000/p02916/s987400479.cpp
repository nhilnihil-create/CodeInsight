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
ll int ans=0;

cin >> N;
vector<ll int > A(N),B(N),C(N);
rep(i,N){
	cin >> A[i];
}
rep(i,N){
	cin >> B[i];
}
rep(i,N-1){
	cin >> C[i];
}


rep(i,N){
	ans += B[A[i]-1];


	if(i!=0){
		if(A[i-1]+1 == A[i]){
			ans += C[A[i-1]-1];
		}
		else{}
	}
	else{}
//cout << B[A[i]-1] << endl;
}
cout << ans << endl;






	return 0;

}

