#include<bits/stdc++.h>
using namespace std;
int check(int a,int b){
	if(a<10&&b<10&&a>0&&b>0)return a*b;
	else return -1;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<check(a,b);
	return 0;
} 