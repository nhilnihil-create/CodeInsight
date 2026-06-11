#include<iostream>
#include<set>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	set<int> dl;
	int p=0;
	int i=1;
	while(1){
		int a=i+p;
		int b=n-i+1;
		int d1=b-a-1;
		int d2=a-1+n-b;
		if(!dl.count(d1)&&!dl.count(d2)&&d1!=d2){
			cout<<a<<" "<<b<<endl;
			dl.insert(d1);
			dl.insert(d2);
		}else{
			p++;
			continue;
		}
		if(i==m) break;
		i++;
	}
	return 0;
}  
