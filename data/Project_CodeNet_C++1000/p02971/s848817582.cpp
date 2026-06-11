#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v,y;
int N;

int main () {
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        v.push_back(x);
        y.push_back(x);
    }
    sort(y.rbegin(),y.rend());

    for(int i=0;i<N;i++){
        if(v[i] == y[0]) {
            cout << y[1] << endl;
        } else cout << y[0] << endl;
    }
    return 0;
}
