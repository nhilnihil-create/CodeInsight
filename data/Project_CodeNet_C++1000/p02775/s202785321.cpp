#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p=1000000007;
int main() {
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int l=s.size(),i=0;
    s+="0";
    int total=0,carry=0;
    while(i<l) {
        int c=(int)s[i]-'0'+carry;
        carry=0;
        if(c==0) {
            i++;
            continue;
        }
        if(c<=4||c==5&&(int)s[i + 1]-'0'<5) {
            total+=c;
            i++;
            continue;
        }
        carry=1;
        total+=10-c;
        i++;
        while(i<l&&(int)s[i]-'0'==9)i++;
    }
    cout<<total+carry<<endl;
    return 0;
}