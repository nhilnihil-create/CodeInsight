#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    int sub;
    sub=k-A.back()+A.at(0);
    for(int i=0; i<n-1; i++){
        sub = max(sub, A.at(i+1) -A.at(i));
    }
    cout << k-sub << endl;
}