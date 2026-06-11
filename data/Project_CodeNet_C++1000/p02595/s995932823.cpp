#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll N,D;
  	cin >> N >> D;
	int count=0;	
	for(ll i=0;i<N;i++){
    	ll x,y;
	    cin >> x >> y;
    	if(x*x + y*y <= D*D){
        	count+=1;
        }
    }
	cout << count << endl;
}