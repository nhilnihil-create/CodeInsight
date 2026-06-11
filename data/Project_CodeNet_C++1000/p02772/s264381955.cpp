#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,a[1000];
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a[i];
        if(a[i]%2==0 && a[i]%3!=0 && a[i]%5!=0){
            cout << "DENIED";
            return 0;
        }
    }
    cout << "APPROVED";
}
