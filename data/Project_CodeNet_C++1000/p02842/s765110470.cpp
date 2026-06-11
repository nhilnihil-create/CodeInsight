#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#define long long

using namespace std;

int main() {
	float n;
	cin>>n;
	if(floor(ceil(n/1.08)*1.08)==n){
		cout<<ceil(n/1.08);
	}
	else{
		if(floor(floor(n/1.08)*1.08)==n){
			cout<<floor(n/1.08);
		}
		else{
			cout<<":(";
		}
	}
	
}

