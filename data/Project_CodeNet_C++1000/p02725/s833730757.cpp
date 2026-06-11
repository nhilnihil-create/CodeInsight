#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> n;

int main(){
	int k,n,af,al,a1,ans=0;
	cin>>k>>n;
	cin>>af;
	a1=af;
	for(int i=0;i<n-1;i++){
		cin>>al;
		ans=max(ans,al-af);
		af=al;
	}
	ans=max(ans,k-al+a1);
	cout<<k-ans<<endl;
	return 0;
}
