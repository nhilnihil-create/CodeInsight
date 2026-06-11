#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){

    int n; cin >> n;
    string s; cin >> s;
    if(n%2==1)cout<<"No";
    else{
    int m = n/2;
    bool flag = true;
    for(int i=0; i<m; i++)
    {
        if(s[i]!=s[m+i]){
            flag = false;
            break;
        }
    }
    if(flag)cout << "Yes";
    else cout << "No";
    }
    return 0;

}
