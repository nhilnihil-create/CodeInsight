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
    int n; cin >> n;
    vector<ll int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<ll int> u(n);
    u[0] = 0; //最初の踏み台は0

    for(int i=0; i<n-1; i++){
        // 前の人より大きいとき踏み台いらない
        if(a[i+1] >= a[i]) continue; 

        u[i+1] = a[i] - a[i+1]; // 踏み台最小値
        a[i+1] += u[i+1];
    }
    

    ll int ans = 0;
    for(int i=0; i<n; i++){
        ans += u[i];
    }

    cout << ans;
}