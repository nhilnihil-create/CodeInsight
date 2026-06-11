#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> d(2);
    int ans_c = 0;
    for(int i=0; i<n; i++){
        cin >> d.at(0) >> d.at(1);
        if(d.at(0) == d.at(1)){
            ans_c += 1;
        }
        else{
            ans_c = 0;
        }
        if(ans_c == 3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}