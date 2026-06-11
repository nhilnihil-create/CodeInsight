#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;





int main() {

ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
string t;
cin>>s>>t;

int cnt=0;

for(int i=0;i<s.size();i++){
    if(s[i]!=t[i]){
        cnt++;
    }
}
cout<<cnt<<"\n";
return 0;
}
