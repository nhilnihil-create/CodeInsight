#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
 
#define rep(n) for(int i=0; i<(n); i++)
#define pb(n) push_back((n))
 
//typedef long long ll;
 
using namespace std;

// vector<bool> p(100000100,true);

// void makep(){
// 	for(int i=0; i<100000100; i++){
// 		if(i<2)p[i]=false;
// 		for(int j=2; j<=sqrt(i); j++){
// 			if(i%j==0){
// 				p[i]=false;
// 				break;
// 			}
// 		}
// 	}
// }

bool is_p(int n){
	if(n<2)return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(){
	int n,cnt=0,a;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		if(is_p(a))cnt++;
	}
	cout<<cnt<<endl;
}