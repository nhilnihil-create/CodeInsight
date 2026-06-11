#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.tie(0)
#define MAXX 100005

string s;
int a[MAXX];
int l[MAXX];
int r[MAXX];

int main()
{
    _FastIO;
    cin >> s;
    vector<int> x;
    vector<int> y;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == 'R')
            x.push_back(i);
        else
            y.push_back(i);
    }
    reverse(x.begin() , x.end());
    int k = 0;
    for(int i = 0; i < y[0]; i++){
        if(s[i] == 'R')
            r[i] = y[0];
    }
    k++;
    for(int i = y[k - 1] + 1; i < n; i++){
        if(s[i] == 'R')
            r[i] = y[k];
    else
        k++;
    }
    k = 0;
    for(int i = n - 1; i >= x[k]; i--){
        if(s[i] == 'L')
            l[i] = x[0];
    }
    k++;
    for(int i = x[k - 1] - 1; i >= 0; i--){
        if(s[i] == 'L')
            l[i] = x[k];
        else
            k++;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            int d = r[i] - i;
            if(d % 2)
                a[r[i] - 1]++;
            else
                a[r[i]]++;
        }
        else{
            int d = l[i] - i;
            if(d % 2)
                a[l[i] + 1]++;
            else
                a[l[i]]++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
