#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool isSorted(int arr[], int temp[], int n){
    for(int i = 0; i < n; i++)
        if(arr[i] != temp[i])
            return false;
    cout << "YES";
    exit(0);
}
int main()
{
    Hello
    int n;
    cin >> n;
    int arr[n + 5], temp[n + 5];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(temp, temp + n);
    isSorted(arr, temp, n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(arr[i], arr[j]);
            isSorted(arr, temp, n);
            swap(arr[i], arr[j]);
        }
    }
    cout << "NO";
    return 0;
}
