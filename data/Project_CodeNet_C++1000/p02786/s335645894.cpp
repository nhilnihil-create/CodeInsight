#include<bits/stdc++.h>
using namespace std;
long int solve(long int h){
    if(h==1){
        return 1;
    }
    else {
        return 1+(2*solve(floor(h/2)));
}}
int main(){
	
		long int h;
		cin>>h;
		cout<<solve(h);
		return 0;
}