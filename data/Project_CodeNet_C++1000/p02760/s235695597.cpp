#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int>v;
    int n;
    int a;
    for (int i = 0; i<9; i++){
        cin>>a;
        v.push_back(a);
    }
    cin>>n;
    set<int>s;
    for (int i = 0; i<n; i++){
        cin>>a;
        s.insert(a);
    }
    int b,c;
    for (int i = 0; i<9; i+=3){
        a = v[i];
        b = v[i+1];
        c = v[i+2];
        if (s.count(a) && s.count(b) && s.count(c)){
            cout<<"Yes";
            return 0;
        }
    }
    for (int i = 0; i<3; i++){
        a = v[i];
        b = v[i+3];
        c = v[i+6];
        if (s.count(a) && s.count(b) && s.count(c)){
            cout<<"Yes";
            return 0;
        }
    }
    a = v[0];
    b = v[4];
    c = v[8];
    if (s.count(a) && s.count(b) && s.count(c)){
        cout<<"Yes";
        return 0;
    }
    a = v[2];
    b = v[4];
    c = v[6];
    if (s.count(a) && s.count(b) && s.count(c)){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}
