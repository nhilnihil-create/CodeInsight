#include <bits/stdc++.h>

using namespace std;

int h1,m1,h2,m2,m;

int main() {
 	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin>>h1>>m1>>h2>>m2>>m;
  	int ans = (h2-h1)*60 + (m2-m1);
  	cout<<max(0,ans-m)<<endl;
}