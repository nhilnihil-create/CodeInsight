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
    int n; cin  >> n;
    vector<char> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }

    int left = 0;
    int right = n-1;
    int ans = 0;
    // 変更する必要がないときはok=1
    bool ok = 1;
    for(int i=0; i<n-1; i++){
        if(c[i]=='W' && c[i+1]=='R') ok = 0;
    }

    if(ok){
        cout << 0;
    }else{
        while(left<right){
            if(c[left]=='W' && c[right]=='R'){
                left++;
                right--;
                ans++;
            }else if(c[left]=='R'){
                left++;
            }else if(c[right]=='W'){
                right--;
            }else{;}
        }
        cout << ans;
    }
}