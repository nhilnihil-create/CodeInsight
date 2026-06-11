#include <bits/stdc++.h>
using namespace std;
int main() {
	int k;
	cin>>k;
	int a,b,count=0;
	cin>>a>>b;
	for (int i=a;i<=b;i++){
	    if (i%k==0){
	        count++;
	    }
	}
	if (count>0){
	    cout<<"OK"<<endl;
	}
	else
	    cout<<"NG"<<endl;
	return 0;
}
