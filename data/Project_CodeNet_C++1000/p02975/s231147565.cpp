#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<long long int, int> num;
    for(int i=0; i<n; i++){
        long long int a;
        cin >> a;
        
        if(num.find(a) == num.end()) num[a] = 1;
        else num[a] += 1;
    }

    if(num.size() <= 3){
        vector<pair<long long int, int>> y;
        for(auto x : num){
            y.push_back(x);
        }

        if((int)y.size() == 3 
        && y[0].second == y[1].second
        && y[1].second == y[2].second
        && ((y[0].first ^ y[1].first) == y[2].first)){
            cout << "Yes" << endl;
            return 0;
        }
        if((int)y.size() == 2
        && y[0].first == 0
        && y[1].second == 2 * y[0].second){
            cout << "Yes" << endl;
            return 0;
        }
        if((int)y.size() == 1
        && y[0].first == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}