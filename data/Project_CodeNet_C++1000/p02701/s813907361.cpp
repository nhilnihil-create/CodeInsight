#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

set<string> s;

int main(){
    AC
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string k;
        cin>>k;
        s.insert(k);
    }
    cout<<s.size()<<endl;
}