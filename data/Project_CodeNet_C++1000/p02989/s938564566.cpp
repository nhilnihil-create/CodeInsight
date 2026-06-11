#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int ans = vec[n/2]-vec[(n/2)-1];
    cout <<ans <<endl;
}