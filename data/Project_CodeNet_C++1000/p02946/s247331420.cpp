#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007

using namespace std;
int main(){
    FAST
    int k,x; cin >> k >> x;
    if(k==1){
        cout << x << endl;
        return 0;
    }
    vector<int>vec;
    for(int y=x;y>=x-k+1;y--){
        vec.pb(y);
    }
    for(int y=x+1;y<=k+x-1;y++){
        vec.pb(y);
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }





    return 0;
}



