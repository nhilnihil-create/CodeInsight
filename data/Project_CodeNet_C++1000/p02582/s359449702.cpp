#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main() {
    int cnt=0,maxl=0;
    string s;
    cin>>s;
    for(char c:s)
        if(c=='R') cnt++;
        else
        {
            maxl=max(maxl,cnt);
            cnt=0;
        }
    cout<<max(maxl,cnt)<<endl;
}
