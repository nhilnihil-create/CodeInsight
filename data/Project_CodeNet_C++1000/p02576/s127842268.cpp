#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n,x,t;
	cin >> n >> x >> t;
	if(n%x==0){
		cout << n/x*t << endl;
	}
	else{
		cout << (n/x+1)*t << endl; 
	}
	return 0;
}