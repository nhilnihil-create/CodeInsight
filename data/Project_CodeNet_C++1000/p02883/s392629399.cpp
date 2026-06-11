//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main() {
    IOS;
    int n, k;
    cin >> n >> k;
    int arr[n], brr[n];
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n; i++) {
        cin >> brr[i];
    }

    sort(arr, arr + n);
    sort(brr, brr + n);

    int low = 0 ;
    int high = 1e16;
    while(low < high) {
        int mid = (low + high) / 2;

        int kk = k;
        for(int i = 0 ; i < n; i++) {
            int mul = arr[i] * brr[n - i -1];
            if(mul <= mid) {
                continue;
            }
            int reduceto = mid / brr[n - i - 1];
            kk -= (arr[i] - reduceto);
        }

        if(kk < 0) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    print(low);
}   

