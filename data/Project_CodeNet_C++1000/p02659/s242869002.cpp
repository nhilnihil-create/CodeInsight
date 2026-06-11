#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;

int main(){
	long long A;
	cin>>A;
	double B;
	cin>>B;
	long long C=B*100+0.5;
	A*=C;
	A/=100;

	cout<<A<<endl;


    return 0;
}