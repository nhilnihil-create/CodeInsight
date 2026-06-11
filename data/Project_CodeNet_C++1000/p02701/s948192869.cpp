#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<string> lottery;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        lottery.insert(s);
    }
    cout<<lottery.size();
}
