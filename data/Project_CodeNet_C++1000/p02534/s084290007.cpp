#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <list>
using namespace std;

int main() {
    int K;
    cin>>K;
    string s = "ACL";
    string s1 = s;
    for(int i = 1; i < K; ++i){
        s += s1;
    }
    cout<<s<<endl;
    return 0;
}
