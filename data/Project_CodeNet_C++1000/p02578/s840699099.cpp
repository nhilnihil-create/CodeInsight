#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);    cout.tie(NULL);
#define forf(i,n) for(int i=0;i<n;i++)
#define foro(i,n) for(int i=1;i<n;i++)
#define ll long long
using namespace std;



void check(int a[],int n){
	ll s;
	s=0;
	foro(i,n){
		if (a[i]-a[i-1]<0){
			
			s+=a[i-1]-a[i];
			a[i]=a[i-1];

		}
	}
	cout<<s;
}

int main(){
	int n;
	 cin>>n;
	 int a[n];
	 forf(i,n) cin>>a[i];
	 check(a,n);
}