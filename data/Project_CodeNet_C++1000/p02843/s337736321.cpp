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
	for(int i=0;i<=x;i++){
		if(i*100<=x && x<=i*105){
			cout << "1" << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}
