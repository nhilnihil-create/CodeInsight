#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int a[n];
    int days = 0;
    for(int i=0; i<m; i++){
        cin >> a[i];
        days += a[i];
    }

    cout << (n >= days ? n-days : -1) <<  endl;
}

    
