#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s1=0,s2 =0,ans;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            s1+=data.at(j);
        }
        for (int j = i; j < n; j++){
            s2+=data.at(j);
        }
        if(i==0){
            ans= abs(s1-s2);
        }
        if(ans > abs(s1-s2))ans=abs(s1-s2);
        s1=0,s2=0;
    }
    cout << ans << endl;
}