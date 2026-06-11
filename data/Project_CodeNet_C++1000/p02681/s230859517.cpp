#include<iostream>
#include<string>
using namespace std;

int main() {
	string s,c;
    cin>>s;
    cin>>c;
    if(c.length() > s.length()) {
        c.erase(c.begin()+s.length(),c.end());
        if(c==s) cout<<"Yes\n";
        else cout<<"No\n";
    }
    else cout<<"No\n";
	return 0;
}