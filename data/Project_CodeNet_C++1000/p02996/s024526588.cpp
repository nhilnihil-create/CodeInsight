#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool ok=true;
    long long time=0;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> a.at(i).at(1) >> a.at(i).at(0);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        time+=a.at(i).at(1);
        if(time>a.at(i).at(0))ok=false;
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}