#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	//
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int m;
    cin>>m;
    int total=0;
    for (int i=0; i<m; ++i){
    	int x;
    	cin>>x;
    	total+=x;
    }
    if(n-total<0){
    	cout<<-1;
    }
    else{
    	cout<<n-total;
    }
    return 0;
}