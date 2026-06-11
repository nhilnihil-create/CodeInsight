#include<iostream>
using namespace std;

int main(){
    int n, i;
    cin >> n;
    int a[256];

    double sum = 0;
    for(i = 0; i < n; i++){
        cin >> a[i];
        sum += (double)1/a[i];
    }
    cout << 1/sum << endl;

    return 0;
}
