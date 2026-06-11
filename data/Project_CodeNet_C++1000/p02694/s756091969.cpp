#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(){
    ull x;
    cin>>x;
    ull sum = 100;
    ull tot = 0;
    while(sum<x){
    	ull res = sum /100;
    	//cout<<res<<"0---";
    	sum += res;
    	tot++;
	}
	cout<<tot;
	return 0;
} 