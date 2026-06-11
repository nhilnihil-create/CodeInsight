#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    int sum =0;
    cin>>s;
    int len = s.length();

    for ( int i =0; i<len; i++ )
        sum = sum + (int)s[i] - (int)'0';
    
    if (sum%9==0)
        cout<<"Yes";
    else
    {
        
        cout<<"No";
    }
    
}