#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

string s;
cin>>s;
if(s.size()%2!=0){cout<<"No"<<endl; return 0;}
//cout<<t.substr(0,s.size())<<endl;
string ans = "";

for (size_t i = 0; i < s.size(); i+=2)
{
 if(s.substr(i,2)!="hi"){cout<<"No"<<endl; return 0;}
}
cout<<"Yes"<<endl;



}
/*vector <int> a(3);
for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }*/