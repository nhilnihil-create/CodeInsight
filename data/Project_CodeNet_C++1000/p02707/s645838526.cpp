#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int mxn = 2e5;
int a[mxn];

int main(){
	//
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    map<int,int> mem;
    for (int i=0; i<n-1; ++i){
    	int x;
    	cin>>x;
    	mem[x]++;
    }
    for (int i=1; i<=n; ++i){
    	cout<<mem[i]<<endl;
    }

}