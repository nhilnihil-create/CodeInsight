// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	ll int n;
    cin>>n;
    ll int a[n];
    ll int b[n];
    for(int i=0;i<n;i++){
          cin>>a[i];
          b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        if(a[i]!=b[n-1]){

            cout<<b[n-1]<<" ";

        }else {

        	cout<<b[n-2]<<" ";

        }
    }
}