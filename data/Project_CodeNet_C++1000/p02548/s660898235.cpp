#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs            v.size()
#define ss            s.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii            pair<int, int>
#define int           long long
#define ull           unsigned long long
#define pb            push_back
#define mpp           make_pair
#define Okay          0
#define pi            3.14159

const int inf = 1e8;
const int cont = 1e18;
const int mod = 1e5;
using namespace std;


void solve(){
   int n;
   cin>>n;
   int cnt = 0;
   for(int i=1; i<n; i++){
        cnt += (n-1)/i;
   }
   cout<<cnt<<endl;
}

int32_t main() {
   Fast;
//   int tst;
//   cin>>tst;
//   for(int i=1; i<=tst; i++){
     solve();
//   }
    return Okay;
}

