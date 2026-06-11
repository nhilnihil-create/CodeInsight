#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ptr=0;
    int cnt=0;
    while(ptr<n){
            cnt++;
        while(s[ptr+1]==s[ptr]){
            ptr++;
        }
    ptr++;
    }
cout<<cnt;
    return 0;
}
