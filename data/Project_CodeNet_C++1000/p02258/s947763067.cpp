#include<iostream>
#include<vector>
using namespace std;

int timeSerialDiff (vector<int> &v){
    int size = v.size();
    if(size < 2){
        return 0;
    }
    int i, max, min, cnt = 0;
    min = v[0];
    max = v[1] - v[0];
    for(i = 1; i < size; i++){
        int diff = v[i] - min;
        max = max < diff ? diff : max;
        min = min > v[i] ? v[i] : min;
    }
    return max;
}
int main(){
    int n, i, x, min, max;
    vector<int> v;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cout << timeSerialDiff(v) << endl;
    return 0;
}