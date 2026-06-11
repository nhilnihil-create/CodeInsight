#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int>Map;
    bool ok=true;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        Map[a]++;
        if(Map[a]==2)ok=false;
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}