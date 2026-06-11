#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[500010];
ll b[500010];
int main(void)
{
    ll i,n,sum=0;
    string s;
    cin >> s;
    s = '.' + s;
    for(i=1; i<s.size(); i++) {
        if(s[i]=='<')
            a[i]=a[i-1]+1;
    }
    for(i=s.size()-1; i>=1; i--) {
        if(s[i]=='>')
            b[i-1]=b[i]+1;
    }
    for(i=0;i<s.size();i++)
        sum+=max(a[i],b[i]);
    cout << sum;
    return 0;
}
