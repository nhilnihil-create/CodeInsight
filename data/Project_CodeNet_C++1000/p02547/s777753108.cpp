#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i) >> b.at(i);
    }
    for(int i=0; i<n-2; i++){
        if(a.at(i)==b.at(i) && a.at(i+1)==b.at(i+1) && a.at(i+2)==b.at(i+2)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}