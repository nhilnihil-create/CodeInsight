#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;

    map<string, int> str;
    for(int i=0; i<n; i++){
        string e; cin>>e;
        str[e]++;
    }
    
    int max_value = INT_MIN;
    string ans;
    for (auto item : str)
        if(item.second>max_value)
            max_value = item.second;
    
    for (auto item : str)
        if(item.second == max_value)
            cout<<item.first<<endl;
}

int main(){
    solve();
    Bye;
}