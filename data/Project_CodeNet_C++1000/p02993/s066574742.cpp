#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    string s;cin>>s;
    rep(i,3)if(s[i+1]==s[i]){
        cout<<"Bad"<<endl;
        return 0;
    }
    cout<<"Good"<<endl;
	return 0;
}