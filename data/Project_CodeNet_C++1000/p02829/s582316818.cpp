// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int64;
// typedef vector<int> vec;
// typedef vector<int64> vec64;
// #define db(x) cout << "> " << #x << ": " << x << "\n";
// #define ss cout << " ";
// #define ct(x) cout << x;
// #define nn cout << "\n";
// #define cts(x) cout << x << " ";
// #define ctn(x) cout << x << "\n";
// #define qr queries();
// void solve();
// void YN(bool b){if (b){ctn("YES");}else{ctn ("NO");}};
// void yn(bool b){if (b){ctn("Yes");}else{ctn ("No");}};
// void queries(){int n;cin >> n;while (n--)solve();}
// // // // // // // // // // // // // // // // // // // // // // // 
// /*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // // //
// int64 q, n;

// void solve(){
//     int n;
//     cin >> n;
//     vec arr (n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++){
//         int mx = i+1;
//         int mxindex = i+1;
//         for (int j = i+2; j< n; j++){
//             if (arr[i] < mx && arr[j] < mx){
//                 ctn("YES");
//                 cout << i+1 << " " << mxindex+1<< " " << j+1 << "\n";
//                 return;
//             }
//             if (arr[j] > mx){
//                 mx = arr[j];
//                 mxindex = j;
//             }
//         }
//     }
//     ctn("NO");
//     return;
// }


// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n;
//     qr;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef vector<int> vec;
typedef vector<int64> vec64;
#define db(x) cout << "> " << #x << ": " << x << "\n";
#define ss cout << " ";
#define ct(x) cout << x;
#define nn cout << "\n";
#define cts(x) cout << x << " ";
#define ctn(x) cout << x << "\n";
#define qr queries();
void solve();
void YN(bool b){if (b){ctn("YES");}else{ctn ("NO");}};
void yn(bool b){if (b){ctn("Yes");}else{ctn ("No");}};
void queries(){int n;cin >> n;while (n--)solve();}
// // // // // // // // // // // // // // // // // // // // // // 
/*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // //
int64 q, n;

void solve(){

    return;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a1,a2;
    cin >> a1 >> a2;
    ctn(6 - (a1 + a2));
    return 0;
}

