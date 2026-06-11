#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
const int mxn=100;
int a[mxn],b[mxn];
int solve(){

	for(int i=0;i+2<n;i++){
		if(a[i]==b[i] && a[i+1]==b[i+1] && a[i+2]==b[i+2])
			return 1;
	}
	return 0;
}
int main(){
cin>>n;
for(int i=0;i<n;i++)
	cin>>a[i]>>b[i];
cout<<((solve()==1)?"Yes":"No");

}
