#include <bits/stdc++.h>
using namespace std;

//n
int main() {
    int n;
    cin >> n;
    vector<int>c;
    vector<int>v;
    while(n--){
        int i;
        cin >> i;
        c.push_back(i);
        v.push_back(i);
    }
    sort(v.begin(),v.end());
    int count = 0;
    for(int i = 0;i < v.size();i++){
        if(v[i] != c[i])
            count++;
    }
    if(count > 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}