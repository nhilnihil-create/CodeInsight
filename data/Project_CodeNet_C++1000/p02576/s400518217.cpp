#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	int n,x,t;
	cin>>n>>x>>t;
	cout<<t*((n-1)/x+1)<<endl;
	return 0;
}