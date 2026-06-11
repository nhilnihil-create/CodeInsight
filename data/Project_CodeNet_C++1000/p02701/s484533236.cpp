#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define endl "\n"

int main(){
    //
    //freopen("input.txt", "r", stdin);
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    set <string> S;
    int n;
    cin>>n;
    for (int i=0; i<n; ++i){
        string temp;
        cin>>temp;
        S.insert(temp);
    }
    cout<<S.size();

}