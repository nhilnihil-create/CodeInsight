#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> array(n,-1);
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        array.at(k-1) = 0;
    }
    if(n > 1){
        if(array.at(0) != 0 && array.at(1) != 0){
        array.at(0) = 1;
        array.at(1) = 2;
    }else if(array.at(0) != 0 && array.at(1) == 0){
        array.at(0) = 1;
    }else if(array.at(0) == 0 && array.at(1) != 0){
        array.at(1) = 1;
    }
    for(int i=2;i<n;i++){
        if(array.at(i) != 0){
            array.at(i) = (array.at(i-1) + array.at(i-2)) % 1000000007;
        }
    }
    cout << array.back() << endl;
    }else{
        cout << 1 << endl;
    }
    
}