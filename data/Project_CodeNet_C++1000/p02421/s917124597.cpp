#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<list>
#include<cctype>
#include<utility>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{
	int taro,hanako;
	taro = hanako = 0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1==s2){
			taro++;hanako++;
		}else if(s1>s2){
			taro += 3;
		}else{
			hanako += 3;
		}
	}
	cout << taro << " " << hanako << endl;
    return 0;
}