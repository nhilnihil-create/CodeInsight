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
	int m,d,cnt=0,a,b;
	string s1,s2,s3;
	cin>>m>>d;
	for(int i=1;i<m+1;i++){
		for(int j=11;j<d+1;j++){
			s1=to_string(j);
			s2=s1.substr(0,1);
			s3=s1.substr(1,1);
			a=stoi(s2);
			b=stoi(s3);
			if(a*b==i && a>=2 && b>=2){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

