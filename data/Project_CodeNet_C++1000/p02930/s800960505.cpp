#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;
int f(int a,int b){
    for(int i=0;i<32;i++){
	if( ( (a>>i)&1 ) != ( (b>>i)&1 ) ) return i; 
    }
    return -1;
}

int main(){
    ll n;
    cin>>n;
    for(int i=0;i<n-1;i++){
	cout<<1+f(i,i+1);
	for(int j=i+2;j<n;j++){
	    cout<<' '<<1+f(i,j);
	}
	cout<<endl;
    }
    return 0;
}
