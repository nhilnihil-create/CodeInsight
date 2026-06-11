#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    sort(d.begin(),d.end());
    int value1 = d[n/2];
    int value2 = d[n/2-1];
    vector <int> ans;
    while(value1>value2){
        ans.push_back(value1);
        value1--;
    }
    cout << ans.size() << endl;
    return 0;
}