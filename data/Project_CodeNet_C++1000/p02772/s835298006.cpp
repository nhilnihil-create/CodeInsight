#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];
    int g = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) {
            g++;
            if(a[i] % 5 == 0 || a[i] % 3 == 0){
                l++;
            }
        }
    }
    if(l == g){
        cout << "APPROVED";
    } else{
        cout << "DENIED";
    }
    
    return 0;
}