#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
	int MIN=a[0],MAX=a[n-1],p=0,m=0;
	for(int i=1;i<n-1;i++){
		if(a[i]>0)p+=a[i];
		else m+=a[i];
	}
	cout<<MAX-m-(MIN-p)<<endl;
	for(int i=1;i<n-1;i++){
		if(a[i]>0){
			cout<<MIN<<" "<<a[i]<<endl;
			MIN-=a[i];
		}else{
			cout<<MAX<<" "<<a[i]<<endl;
			MAX-=a[i];
		}
	}
	cout<<MAX<<" "<<MIN<<endl;
    return 0;
}
