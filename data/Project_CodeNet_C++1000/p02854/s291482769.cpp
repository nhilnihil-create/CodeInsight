#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long total=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        total+=a[i];
    }
    long long com=0,com1=0,com2=0;
    for(int i=0;i<n-1;i++){
        com+=a[i];
        if(com<=(total/2)&&(com+a[i+1])>(total/2)){
            com1=com;
            com2=com+a[i+1];
            break;
        }
    }
    cout << min(abs(2*com1-total),abs(2*com2-total)) << endl;
}