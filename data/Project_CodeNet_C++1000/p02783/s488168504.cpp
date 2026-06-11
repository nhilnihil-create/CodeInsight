#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,a;
	cin>>h>>a;
	int ret = h/a;
	if(h%a) ret++;
	cout<<ret;
}