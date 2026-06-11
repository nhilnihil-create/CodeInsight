#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	double n,a;
	cin>>n;
	a=int(n/2);
	a=n-a;
	cout<<fixed<<setprecision(6)<<a/n<<endl;
}