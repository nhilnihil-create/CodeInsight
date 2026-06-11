#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
    int a,c,ans,tmp;
    string s;
 
    ans = tmp = 0;
     cin >> a;
    vector<int>v(a);
    vector<int>b(a);
    for(int i = 0;i < a;i++){
        cin >> v[i];
    }
    b = v;     

   
    sort(v.begin(),v.end());
    for(int i = 0;i < a;i++){
        if(b[i] != v[i]){
            tmp++;
        }
    }
    if(tmp <=2){
        cout << "YES";
    }else{
        cout <<"NO";
    }
}
