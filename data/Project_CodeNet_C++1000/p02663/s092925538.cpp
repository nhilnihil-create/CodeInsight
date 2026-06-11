#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN = 1e5;

 const int mod =1e9+7; 
ll res = INT_MAX;
ll x =10;
 
int main()
 {
	//code
ll h1,m1,h2,m2,k;
cin>>h1>>m1>>h2>>m2>>k;
ll hd = h2-h1;
ll md = m2-m1;

 cout<<hd*60+md-k<<"\n";
}