#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;
    long long int s;
    cin>>n>>k>>s;
    int count=0;
    for (int i=0;i<n;i++) {
        if (count<k) {
            count++;
            cout<<s;
        } else {
            if (s!=1000000000) {
                cout<<s+1;
            } else {
                cout<<s-1;
            }
        }
        if (i!=n-1) {
            cout<<" ";
        } else {
            cout<<endl;
        }
    }
}