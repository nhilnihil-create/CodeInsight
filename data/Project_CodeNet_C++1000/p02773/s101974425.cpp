#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define endll "\n"

#define fin             freopen("input.txt","r",stdin);
#define fout            freopen("output.txt","w",stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string , int > mp;
    string s;
    while(n--){
        cin >> s;
        if(mp.count(s)==false){
            mp[s]=1;
        }
        else{
            mp[s]++;
        }
    }
    int mx=0;
    for(auto it:mp){
        if(it.second>mx) mx=it.second;
    }
    for(auto it:mp){
        if(it.second==mx){
            cout << it.first << endl;
        }

    }

    return 0;
}

