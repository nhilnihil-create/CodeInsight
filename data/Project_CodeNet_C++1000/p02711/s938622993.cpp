#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
using namespace std;

int main(){
    FAST
    string s; cin >> s;

    for(int i=0; i<3; i++){
        if(s[i]-'0' == 7){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            continue;

        }
    }
    cout << "No" << endl;


    return 0;
}
