#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

string s = "";

int main(){
    AC
    ll n;
    cin>>n;
    while(n>0){
        int m = n%26;
        if(m==0){
            s = 'z'+s;
            if((n-26)%26==0)
                n-=26;
        }
        else
            s = (char)('a'+(m-1)) + s;
        n/=26;
    }
    cout<<s<<endl;
}