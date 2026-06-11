#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
cin>>a;
int sum=0;
for(auto c:a){
	sum+=(c -'0');
}

(sum%9==0)?cout<<"Yes" : cout<<"No";}
