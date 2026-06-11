/*
 * main.cpp
 *
 *  Created on: ??‏/??‏/????
 *      Author: Israa
 */

#include<bits/stdc++.h>
using namespace std;


int n, k, sum, arr[1005];

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n; i++) {
    	cin>>arr[i];
    }
    
    sort(arr, arr+n);
    
    for(int i=0; i<k; i++) {
    	sum += arr[i];
    }
    
    cout<<sum;
	return 0;
}
