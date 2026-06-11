#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ; cin >> n; int mx =0;
    map < string , int > m;
    for (int x=0;x<n;x++){
        string s; cin >> s;
        m[s]++;
        mx = max (m[s],mx);
    }
    for (auto it=m.begin();it!=m.end();it++){
        if (it->second==mx){
            cout << it->first<<endl;
        }
    }
}
