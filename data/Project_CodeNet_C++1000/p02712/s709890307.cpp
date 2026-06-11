#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> n;

int main(){
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i%3!=0&&i%5!=0){
			ans+=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}