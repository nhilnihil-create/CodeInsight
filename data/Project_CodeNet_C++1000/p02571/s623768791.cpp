#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),x=t.size();
    int p = 0;
    int res = 2000;
    for(int i=0;i<n-(x-1);i++){
    	//cout<<i<<endl;
    	int curr = 0;
    	for(int j=p;j<x;j++){
    		if(s[i+j]!=t[j])curr++;
    	}
    	res = min(res,curr);
    }
    cout<<res<<endl;

    return 0;
}