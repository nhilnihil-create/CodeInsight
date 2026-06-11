#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    array.at(0) = 1000001;
    for(int i=1;i<n;i++){
        int b;
        cin >> array.at(i);
    }
    array.push_back(1000001);
    int sum = 0;
    for(int i=0;i<array.size()-1;i++){
        sum += min(array.at(i),array.at(i+1));
    }

    cout << sum << endl;
}