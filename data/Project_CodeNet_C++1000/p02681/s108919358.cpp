#include<bits/stdc++.h>
using namespace std;
int main() {
	string s,c;
    cin>>s;
    cin>>c;
    c.erase(c.begin()+s.length(),c.end());
    if(c==s) cout<<"Yes";
    else cout<<"No";
	return 0;
}



