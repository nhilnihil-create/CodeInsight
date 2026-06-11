
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : September 11, 2020 3:22 PM
 *    Problem Name  : C - Poll
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc155/tasks/abc155_c
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    set<string>se;
    map<string , int> mp;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;

        if(se.count(s)){
            mp[s]++;
        }
        else{
            se.insert(s);
            mp[s] = 1;
        }
    }

    int ans = 0;
    set<string>res;

    for(auto x: mp){
       ans = max(ans,x.second);  
    }

    for(auto x: mp){
        if(ans == x.second){
            cout << x.first << endl;
        }
    }
    return 0 ;
}
