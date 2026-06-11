#include <bits/stdc++.h>
#define ll long long
#define Arman_Sykot ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
using namespace std;

int main()
{
/*********************/
// Author:
        Arman_Sykot;
/*********************/
    
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    return 0;
}
