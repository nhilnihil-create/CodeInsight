#include<bits/stdc++.h>
using namespace std;
#define size1 10
int main(){
	int n;
	cin>>n;
	vector<int> p(n),q(n);
	vector<int> sorted;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=0;i<n;i++)
		cin>>q[i];
	sorted=p;
	int a=0,b=0;
	do{
		a++;
	}while(next_permutation(p.begin(),p.end()));
	do{
		b++;
	}while(next_permutation(q.begin(),q.end()));
	cout<<abs(a-b)<<endl;
}