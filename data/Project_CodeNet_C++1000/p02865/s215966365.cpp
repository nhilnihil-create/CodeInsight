#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int count=0;
    for (int i=1;i<n;i++) {
        if (i<n-i) {
            count++;
        }
    }
    cout<<count<<endl;
}