#include<iostream>

using namespace std;

int main(){

    int n;
    int k;
    int q;

    cin >> n;
    cin >> k;
    cin >> q;

    int a[100000];

    for (int i=0;i<q ;i++) cin >> a[i];

    int b[100000];

    for (int i=0;i<n;i++) b[i] = k-q;

    for (int i=0;i<q;i++) 
        b[a[i]-1]=b[a[i]-1]+1;

    for (int i=0;i<n;i++)
        if (b[i] > 0)
        cout << "Yes" << endl;
        else cout << "No" << endl;
}