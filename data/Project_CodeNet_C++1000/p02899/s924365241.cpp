#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        ans.at(a-1)=i+1;
    }
    for(int i=0;i<n;i++){
        if(i!=n-1)cout << ans.at(i) << " ";
        else cout << ans.at(i) << endl;
    }
    return 0;
}