#include <bits/stdc++.h>
#include <math.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> hai(n);
    for(int i = 0; i < n; i++){
        cin >> hai[i];
    }
    int sum = 1;
    int mini = hai[0];

    for(int i = 1; i < n; i++){
        if(mini > hai[i]){
            sum++;
            mini = hai[i];
        }
    }
    cout << sum << endl;


}