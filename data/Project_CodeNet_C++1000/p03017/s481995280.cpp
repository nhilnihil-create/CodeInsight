#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    std::deque<char> line;
    string s;
    cin>>s;
    s="#"+s+"#";
    for (int i=0;i<s.size();i++) {
        line.emplace_back(s[i]);
    }
    if (c<d) {
        for (int i=b;i+2<=d;i++) {
            if (line[i+1]=='#'&&line[i+2]=='#') {
                cout<<"No"<<endl;
                return 0;
            }
        }
        for (int i=a;i+2<=c;i++) {
            if (line[i+1]=='#'&&line[i+2]=='#') {
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    } else {
        for (int i=b;i<=d;i++) {
            if (line[i-1]=='.'&&line[i]=='.'&&line[i+1]=='.') {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
}