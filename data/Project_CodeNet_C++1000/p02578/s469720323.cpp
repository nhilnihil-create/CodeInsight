#include <iostream>
using namespace std;
int a[200006];
int main () {
    int N;
    cin >> N;
    long long int sum=0;
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }
    for (int i=0; i<N-1; i++) {
        if (a[i]>a[i+1]) {
            sum=sum+(a[i]-a[i+1]);
            a[i+1]=a[i];
        }
    }
    cout << sum << endl;
}