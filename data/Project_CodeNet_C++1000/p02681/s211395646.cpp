#include<bits/stdc++.h>
using namespace std;
int main() {
	string s,c;
    cin>>s;
    cin>>c;
    c.erase(c.begin()+s.length(),c.end());
    if(c==s) cout<<"Yes\n";
    else cout<<"No\n";
	return 0;
}



