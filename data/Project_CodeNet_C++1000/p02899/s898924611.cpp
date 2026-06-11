#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int t;
    cin >> t;
    vector<int> vec;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vector<int> vec2(t);
    for(int i =0; i<t; i++){
      vec2[vec[i]-1]=i+1;
    }
    for(int i=0; i<t; i++){
        cout << vec2[i]<<" ";
    }
}