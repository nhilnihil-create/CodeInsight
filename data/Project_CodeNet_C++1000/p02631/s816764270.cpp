#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int tot=0;
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        tot ^= a.at(i);
    }
    for(int i=0; i<n; i++){
        cout << (tot^a.at(i)) << " ";
    }
    cout << endl;
}