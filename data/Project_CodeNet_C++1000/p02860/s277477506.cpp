#include<bits/stdc++.h>
#include<vector>
#define inf 10000000000000
#define ll unsigned long long 
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;
// lower_bound 
 // it returns pos of the elmnt which is not less then the query elmnt
int main(){
    int n, flag = 0; cin >> n;
    string str; cin >> str;
    unordered_map<char, int>mp;
    for(auto i : str)
        mp[i]++;

    int freq = mp[str[0]];

    for(auto i  : mp){
        if(i.second % 2 != 0){
            flag=1;break;
        }
    }

    if(flag == 1 || str.size() == 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

}


