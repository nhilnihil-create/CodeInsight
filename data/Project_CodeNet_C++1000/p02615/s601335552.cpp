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
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // 降べきの順
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    ll int ans = a[0];
    for(int i=1; i<n-1; i++){
        if(i % 2 == 0) ans += a[i/2];
        else ans += a[i/2 + 1];
    }

    cout << ans;

}