#include<bits/stdc++.h>
using namespace std;
using lli = long long;
const int INF = 1e9;
string s;

int main(void){
    cin >> s;
    int n = s.size()+1;
    vector<int> a(n, -1);
    if(s[0] == '>') a[0] = INF;
    else a[0] = 0;
    if(s[s.size()-1] == '>') a[n-1] = 0;
    else a[n-1] = INF;
    for(int i = 1; i < n-1; i++){
        if(s[i-1] == '<' && s[i] == '>') a[i] = INF;
        else if(s[i-1] == '>' && s[i] == '<') a[i] = 0;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            int j;
            j = 1;
            while(i-j > 0 && a[i-j] == -1){
                a[i-j] = j;
                j++;
            }
            j = 1;
            while(i+j < n && a[i+j] == -1){
                a[i+j] = j;
                j++;
            }
        }
    }
    lli res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == INF){
            if(i == 0){
                a[i] = a[i+1]+1;
            }else if(i == n-1){
                a[i] = a[i-1]+1;
            }else{
                a[i] = max(a[i-1]+1, a[i+1]+1);
            }
        }
        res+=a[i];
    }
    cout << res << endl;
    return 0;
}
