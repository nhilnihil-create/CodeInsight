/*
 * main.cpp
 *
 *  Created on: ??‏/??‏/????
 *      Author: Israa
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string s, k;
	int cnt = 0;
	cin>>s>>k;
	for(int i=0; i<s.length(); i++) {
	    if(s[i] != k[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
