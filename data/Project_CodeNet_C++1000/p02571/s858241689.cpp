//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

int main (){
    string s, t; cin >> s >> t;

    int ma_size = s.size()-t.size()+1;
    int t_size = t.size();
    int ans = t.size();
    for(int i=0; i<ma_size; i++){
        int sans = t.size();
        int u = i;
        for(int j=0; j<t_size; j++){
            if(s[u]==t[j]) sans--;
            u++;
        }
        if(sans < ans) ans = sans;
    }
    cout << ans;

}