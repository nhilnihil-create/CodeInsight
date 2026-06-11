#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	int n,k,t,d,num=0;
	map <int,int> p;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>d;
		for(int j=0;j<d;j++){
			cin>>t;
			if(p[t]==0){
				p[t]=1;
				num++;
			}
		}
	}
	cout<<n-num<<endl;
	return 0;
}
