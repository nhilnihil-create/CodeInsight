#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    int count=0;
    int mini=n+1;
    for(int i=0;i<n;i++){
        mini=min(mini,p[i]);
        if(p[i]==mini) count++;
    }
    cout << count << endl;
    return 0;
}