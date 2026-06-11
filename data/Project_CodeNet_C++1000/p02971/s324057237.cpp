#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr.at(i);
    vector<int> copy = arr;
    sort(arr.begin(),arr.end());
    int max1 = arr.at(n-1);
    int max2 = arr.at(n-2);
    for(int i=0;i<n;i++){
        if(copy.at(i) == max1){
            cout << max2 << endl;
        }else{
            cout << max1 << endl;
        }
    }
}