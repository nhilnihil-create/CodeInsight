#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<long long> array(n);
    for(int i=0;i<n;i++){
        cin >> array.at(i);
    }
    sort(array.begin(),array.end());
    int size = array.size() -1;
    for(int i=0;i<k;i++){
        if(size < 0) break;
        array.at(size) = 0;
        size --;
    }

    long long sum = 0;
    for(int i=0;i<n;i++) sum+=array.at(i);
    cout << sum << endl;
}