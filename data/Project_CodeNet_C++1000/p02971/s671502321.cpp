#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<int>vec;
    vector<int>vec2;
    for(int i =0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
        vec2.push_back(a);
    }
    int mx = *max_element(vec.begin(),vec.end());
    sort(vec2.begin(),vec2.end());
    for(int i=0; i<vec.size(); i++){
        if(vec[i]!=mx){
            cout << mx <<endl;
        }else{
            cout << vec2[n-2] <<endl;
        }
    }      
}