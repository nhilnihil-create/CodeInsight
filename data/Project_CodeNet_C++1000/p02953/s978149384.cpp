#include <bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin >> n;
   vector <long> h(n);
    for(long i = 0; i < n; i++)cin>>h[i];
    if(n==1){
        cout << "Yes" << endl;
        return 0;
    }
 
    for(long i = (n-1); i > 0; i--){
        if(h[i-1]>(h[i]+1)){
            cout << "No" << endl;
            return 0;
        }else if(h[i-1]>h[i]){
            h[i-1]--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}