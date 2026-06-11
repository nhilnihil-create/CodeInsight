#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int search = 1, cntr = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == search) search ++;
        else cntr++;
    }
    if(search == 1 && cntr) cout << -1;
    else cout << cntr;
    return 0;
}