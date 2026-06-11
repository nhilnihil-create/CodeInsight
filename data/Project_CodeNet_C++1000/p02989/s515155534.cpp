#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    sort(array.begin(),array.end());
    int back = array.at(n/2);
    int front = array.at((n-2)/2);
    cout << back - front << endl;
}