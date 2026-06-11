#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a,b;
    cin>>a>>b;
    long long int c=a+b;
    if(c%2==0){
    	cout<<c/2;
	}
	else{
		cout<<"IMPOSSIBLE";
	}
    return 0;
}