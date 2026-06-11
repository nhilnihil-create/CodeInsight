#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main() {
  int A[1010101];
  int num[1010101] = {};
  int N,i,j,x;
  cin >> N;
  int g=0;
  rep(i, N) {
    cin >> A[i];
    g = gcd(g, A[i]);
    num[A[i]]++;
  }

  for(i=2;i<=1000000;i++) {
		x=0;
		for(j=i;j<=1000000;j+=i) x+=num[j];
		if(x>=2) break;
	}

	if(i==1000001) {
		cout<<"pairwise coprime"<<endl;
		return 0;
	}

	if(g==1) {
		cout<<"setwise coprime"<<endl;
	}
	else {
		cout<<"not coprime"<<endl;
	}
  return 0;
}
