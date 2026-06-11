#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<long int> a(n);
    long long int half=0;
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        a.at(i)*=2;
        half+=a.at(i);
    }
    half/=2;
    long long int cut=1e18;
    long long int c=0;
    for(int i=0; i<n-1; i++){
        c+=a.at(i);
        cut=min(cut,abs(half-c));
    }
    cout << cut << endl;
}