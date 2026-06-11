#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include <set>
#include <queue>
#include <iterator>
#include <bitset>
#include <bits/stdc++.h>
#include <vector>
#include <cctype>
#include <algorithm>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--) 
#define pi             acos(-1)         
 
using namespace std;
 
ll i,j,temp;

 
int main(){_

	int a,b,c;
	cin>>a>>b>>c;

	temp = a;
	a = b;
	b = temp;

	temp = a;
	a = c;
	c = temp;

	cout<<a<<" "<<b<<" "<<c<<endl;

	return 0;

}