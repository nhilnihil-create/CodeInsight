/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/
#include <bits/stdc++.h>
using namespace std;
 
// #define ll long long int
// #define fi first
// #define se second
// #define pb push_back
// #define all(a) (a).begin(), (a).end()
// #define debug(a) cout << #a << " = " << a << " ";
// #define endl "\n"

// const int  MOD=1000000007 ;

int main() {
    string s;
    cin>>s;
    if(s=="SUN"){
        cout<<"7\n";
    } else if(s=="MON"){
        cout<<"6\n";
    } else if(s=="TUE"){
        cout<<"5\n";
    } else if(s=="WED"){
        cout<<"4\n";
    } else if(s=="THU"){
        cout<<"3\n";
    } else if(s=="FRI"){
        cout<<"2\n";
    } else {
        cout<<"1\n";
    }
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     long int t = 1;
//     // cin>>t;
//     for (long int tt = 1; tt <= t; tt++) {
//         solve();
//     }
//     return 0;
// }