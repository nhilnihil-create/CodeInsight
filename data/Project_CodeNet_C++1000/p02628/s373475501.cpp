#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int i = 0;
    while (i < k){
        sum += v[i];
        i++;
    }
    cout << sum << endl;
}