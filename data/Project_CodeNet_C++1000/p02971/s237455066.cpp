#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
        m[a[i]]++;
    }

    auto mx = m.rbegin();
    int g = mx->first;

    if(mx->second != 1){
        for(int i=0; i<n; ++i)
            cout << g << endl;
    }
    else{
        ++mx;
        int s = mx->first;

        for(int i=0; i<n; ++i){
            if(a[i]==g)
                cout << s << endl;
            else
                cout << g << endl;
        }
    }
}