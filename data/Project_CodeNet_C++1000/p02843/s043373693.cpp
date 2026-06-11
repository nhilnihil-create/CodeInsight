#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	long long x;
	cin >> x;
	if(x%100==0 || x%101==0 || x%102==0 || x%103==0 || x%104==0 || x%105==0){
		cout << "1" << endl;
		return 0;
	}
	int x1000=x%10000;
	int x1=x1000/100;
	for(int a=0;a<=x1;a++){
		for(int b=0;b<=x1;b++){
			for(int c=0;c<=x1;c++){
				for(int d=0;d<=x1;d++){
					for(int e=0;e<=x1;e++){
						for(int f=0;f<=x1;f++){
							if(a*100+b*101+c*102+d*103+e*104+f*105==x1000){
								cout << "1" << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "0" << endl;		
	return 0;
}
