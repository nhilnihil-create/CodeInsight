#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> k >> n;
    vector<int> array(n),d_array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);

    for(int i=0;i<n;i++){
        if(i != 0){
            d_array.at(i) = array.at(i) - array.at(i-1);
        }else{
            d_array.at(0) = array.at(i) + k - array.at(n-1);
        }
    }

    int m = -1;
    for(int i=0;i<n;i++){
        if(m < d_array.at(i)) m = d_array.at(i);
    }
    
    cout << k - m << endl;
}