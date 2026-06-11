#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int t;
    cin >> t;
    vector<int> vec;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    double count =vec[0];
    double ans = 0;
    for(int i=1; i<vec.size(); i++){
        ans = (count+vec[i])/2;
        count = ans;
    }
    cout << ans <<endl;
}