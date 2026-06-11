#include"bits/stdc++.h"
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
	int n;
	int total=0,before_total=0;
	cin>>n;

	while(total<n){
		total+=1000;
	}

	cout<<total-n<<endl;

	return 0;
}