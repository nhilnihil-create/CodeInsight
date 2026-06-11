#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

string a, b;

int main(){
    AC
    cin>>a;
    cin>>b;
    int ans=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i])
            ans++;
    } 
    cout<<ans<<endl;
}