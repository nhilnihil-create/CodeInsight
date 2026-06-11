#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
    	if(s[i]!=s[n-1-i]){
    		cout<<"No";
    		return 0;
    	}
    }
    for(int i=0;i<(n-1)/2;i++){
    	if(s[i]!=s[(n-1)/2-1-i]){
    		cout<<"No";
    		return 0;
    	}
    }
    for(int i=(n+1)/2;i<n;i++){
    	if(s[i]!=s[n-1-i]){
    		cout<<"No";
    		return 0;
    	}
    }
    cout<<"Yes";
 
	return 0;
}