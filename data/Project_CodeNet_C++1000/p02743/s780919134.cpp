#include <bits/stdc++.h>
using namespace std;

int main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 long long a,b,c;
 cin>>a>>b>>c;
 if(c-a-b<0){
	 cout<<"No";
 }
 else if((c-a-b)*(c-a-b)>4*a*b){
	 cout<<"Yes";
 }
 else{
	 cout<<"No";
 }
}   