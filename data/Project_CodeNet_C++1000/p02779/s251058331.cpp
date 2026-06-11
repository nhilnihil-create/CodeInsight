#include <bits/stdc++.h>
using namespace std;

int main(){
    map<long long,int> dict;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(dict.count(a)){
            cout << "NO" << endl;
            return 0;
        }else{
            dict[a] = 1;
        }
    }
    cout << "YES" << endl;
}