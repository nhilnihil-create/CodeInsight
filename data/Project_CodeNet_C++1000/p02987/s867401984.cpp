#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define fore(i,x,n) for(int i=x;i<n;i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define ordenar(a) sort(all(a))
typedef long long ll;
typedef vector<int> vi;

string a;
set<char> b;

int main(){
    IOS

    cin>>a;

    for(auto it : a){
        b.insert(it);
    }

    if(b.size() == 2) cout<<"Yes";
    else cout<<"No";

    return 0;
}