#include<iostream>
#include<string>
using namespace std;

int main() {
	string s,c;
    cin>>s;
    cin>>c;
    int len=c.length();
    char str=c[--len];
    c.erase(c.begin()+s.length(),c.end());
    if(c==s&&str>='a'&&str<='z') cout<<"Yes";
    else cout<<"No";
	return 0;
}
