#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;
#define N 200010

int main() {
    string s,t;cin>>s>>t;
    int ans=t.length();
    for(int i=0; i<=s.length()-t.length(); i++){
        int tmp=0;
        for(int j=0; j<t.length(); j++){
            if(t[j]!=s[i+j]) tmp++;
        }
        ans = min(ans, tmp);
    }

    cout<<ans<<endl;


    return 0;
}