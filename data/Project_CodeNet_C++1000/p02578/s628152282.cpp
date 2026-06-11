#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	long long n,a,ans=0,cur;
	cin>>n>>cur;
	for(int i=1;i<n;i++){
		cin>>a;
		if(a<=cur){
			ans+=cur-a;
		}else{
			cur=a;
		}
	}
	cout<<ans<<endl;
	return 0;
}