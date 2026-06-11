#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    for (int i = 0; i < b; i++){
        cout<<a;
    }
    cout<<endl;
}