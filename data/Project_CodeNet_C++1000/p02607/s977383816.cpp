#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(i%2==0 && a[i]%2!=0){
            count = count + 1;
        }
    }
    cout << count << endl;
    return 0;
}
