#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	int m1,m2,d1,d2;
	cin>>m1>>d1>>m2>>d2;
	if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12){
		if(d1==31){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}else if(m1==2)
		if(d1==28){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	else if(m1==4||m1==6||m1==9||m1==11){
		if(d1==30){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}

