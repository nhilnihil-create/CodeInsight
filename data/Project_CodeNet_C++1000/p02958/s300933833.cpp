#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,c = 0;
    cin >> n;
    int data[n];
    
    for(int i=0;i<n;i++) data[i] = i+1;
    
    for(int i=0;i<n;i++){
        int a_i;
        cin >> a_i;
        if(data[i] != a_i) c++;
    }
    
    if(c == 0 || c == 2){
        cout << "YES" <<endl;
    }
    else{
        cout << "NO" <<endl;
    }
}