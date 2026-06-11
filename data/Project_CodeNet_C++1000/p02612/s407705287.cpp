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
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	if(n%1000==0){
		cout<<0;
	}
	else{
		cout<<1000-n%1000;
	}
}