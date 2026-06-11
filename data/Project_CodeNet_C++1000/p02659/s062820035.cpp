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
    ll int a; cin >> a;
    double b; cin >> b;
    
    // これだとなぜかACにならない
    b *= 100; // 小数点以下2桁を利用して整数にする
    b += 0.001;
    ll int bb = static_cast<ll int>(b);
    // ll int bb = b*100 + 0.001;

    ll int ans = a * bb;
    ans /= 100;
    
    cout << ans;
}