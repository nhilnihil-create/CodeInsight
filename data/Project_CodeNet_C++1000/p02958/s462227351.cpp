#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c=0;
    cin >> n;
    int arr1[n],arr2[n];
    for(int i=0; i<n; i++){
        cin >> arr1[i];
        arr2[i]=arr1[i];
    }
    sort(arr1, arr1+n);
    for(int i=0; i<n; i++){
        if(arr1[i]!=arr2[i])
            c++;
    }
    if(c==0 || c==2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
