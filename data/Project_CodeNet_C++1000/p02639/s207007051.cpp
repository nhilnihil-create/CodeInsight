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
    int a[5];
    scanArray(a,5);
    for(int i=0; i<5; i++){
        if(a[i] == 0){
            cout << i+1 << endl;
        }
        else{
            continue;
        }
    }




    return 0;
}
