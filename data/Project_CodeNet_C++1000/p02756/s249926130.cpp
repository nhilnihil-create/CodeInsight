// // Hail god Yato
 
// #include <bits/stdc++.h> 
// using namespace std;
 
// #define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// typedef long long ll;
// const ll MOD = 1000000007;
// const ll INF = 1e18;
// const ll MAX = 100001;
// //
// //
// void solve(){
//     string str;
//     cin>>str;
//     string front, back;
//     int cur = 1;
//     int q;
//     cin>>q;
//     while(q--){
//         int type;
//         cin>>type;
//         if(type == 1)
//             cur = cur*-1;
//         else{
//             char ch;
//             cin>>type>>ch;
//             if(type == 1){
//                 if(cur == 1)
//                     front.push_back(ch);
//                 else
//                     back.push_back(ch);
//             }
//             else
//                 if(cur == 1)
//                     back.push_back(ch);
//                 else
//                     front.push_back(ch);
//         }
//     }
//     if(cur == -1)
//         swap(front, back);
//     cout<<front<<str<<back;
// }
// int main(){ 
//         hs;
//         ll t;
//         t=1;
//         // cin>>t;
//         for (int i=1; i<=t; i++){
//                 //cout<<"Case #"<<i<<": ";
//                 solve();
//          }
//         return 0; 
// }


// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    string str;
    int q;
    cin>>str>>q;
    deque<char> store;
    for(char ch : str)
        store.push_back(ch);
    int cur = 1;
    while(q--){
        int type;
        cin>>type;
        if(type == 1)
            cur *= -1;
        else{
            char ch;
            cin>>type>>ch;
            if(cur == -1)
                type = type^3;
            if(type == 1)
                store.push_front(ch);
            else
                store.push_back(ch);
        }
    }
    if(cur == -1)
        reverse(store.begin(), store.end());
    for(char ch : store)
        cout<<ch;
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}