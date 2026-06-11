#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int b=a;
    vector<int> data(a);
    for(int i=0; i<data.size(); i++){
        data.at(i) = b;
        b--;
    }

    double count = 0;
    for(int i=0; i<data.size(); i++){
        if(data.at(i) % 2 != 0) count++;
    }

    double ans = count / a;
    cout << fixed << setprecision(15);

    cout << ans << endl;
}