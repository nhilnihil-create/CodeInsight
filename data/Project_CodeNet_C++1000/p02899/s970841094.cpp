#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;

int n;
struct Seq{
	int t,id;
}a[M];

bool operator<(const Seq& a,const Seq& b){
	return a.t<b.t;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].t;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		cout<<a[i].id<<" ";
	}
	return 0;
}
