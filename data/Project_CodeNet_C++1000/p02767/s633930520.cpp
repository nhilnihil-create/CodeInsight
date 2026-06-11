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
    double count = accumulate(vec.begin(),vec.end(),0);
    int ans = 0;
    for(int i=0; i<vec.size(); i++){
        int num = abs(vec[i]-round(count/t));
        ans += pow(num,2);
    }
    cout << ans <<endl;
}