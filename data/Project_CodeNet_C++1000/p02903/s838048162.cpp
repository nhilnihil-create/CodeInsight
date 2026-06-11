#include<bits/stdc++.h>
#define YY "YES\n"
#define NN "NO\n"
#define LL long long
using namespace std;

int a,b,h,w;
int main(){
	cin>>h>>w>>a>>b;
	for (int i=1;i<=b;i++){
		for (int j=1;j<=a;j++) cout<<0;
		for (int j=1;j<=w-a;j++) cout<<1;
		cout<<"\n";
	}
	for (int i=1;i<=h-b;i++){
		for (int j=1;j<=a;j++) cout<<1;
		for (int j=1;j<=w-a;j++) cout<<0;
		cout<<"\n";
	}
}