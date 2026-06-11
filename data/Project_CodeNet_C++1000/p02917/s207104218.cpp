#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<numeric>

#define rep(i,p) for(long long int i=0;i<p;i++)
#define reep(i,p) for(long long int i=1;i<=p;i++)
#define ll long long

using namespace std;

int main(){
ll int N;
cin >> N;

vector<ll int > B(N-1);
vector<ll int > A(N);
rep(i,N-1){
	cin >> B[i];
}
if(N==2){
	cout << B[0]*2;
}
else{
ll int ans = 0;
A[0] = B[0];
A[N-1] = B[N-2];

for(long long int i=1;i<N-1;i++){
	A[i] = min(B[i],B[i-1]);
	
}

cout << accumulate(A.begin(),A.end(),0);

}








	return 0;

}

