#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s;
    cin>>s;
    int n=s.size(),i=0;
    ll ans=0;
    while(i<n){
        ll left=0,right=0;
        while(i<n&&s[i]=='<'){
            left++;
            i++;
        }
        while(i<n&&s[i]=='>'){
            right++;
            i++;
        }
        if(left<right) left--;
        else right--;
        ans+=left*(left+1)/2+right*(right+1)/2;
    }
    cout<<ans;
}