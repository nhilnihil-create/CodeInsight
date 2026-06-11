#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int n;
	while(cin>>n){
		int cnt=0;
		for(int a=0;a<=9;a++)
			for(int b=0;b<=9;b++)
				for(int c=0;c<=9;c++){
					if(a+b+c>n)break;
					if(n-(a+b+c)>9)continue;
					cnt++;
				}
		cout<<cnt<<endl;
	}
	return 0;
}