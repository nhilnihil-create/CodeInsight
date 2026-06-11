#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w,n; cin>>h>>w>>n;
	int mx=max(h,w);
	cout<<(n+(mx-1))/mx<<endl;
}