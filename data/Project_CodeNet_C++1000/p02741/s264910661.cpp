#include<iostream>
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int x[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main(){
	AC;
	int n;
	cin>>n;
	cout<<x[n-1]<<"\n";
	//cout<<"The "<<n<<"-th element is "<<x[n-1]<<".\n";
}