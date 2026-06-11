#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
int main() {
    fastio ;
    ll len;
    cin>>len;
    string s;
    cin>>s;
    int c =0 ;
    ll j = len -1;
    int i=0;
    while(j > i) {

        while(s[i] == 'W' && s[j] == 'R' && j > i) {
            swap(s[i],s[j]);
            c++;
            i++;
            j--;
        }
        if(s[i] == 'R')i++;
        if(s[j] == 'W')j--;
    }
    cout<<c<<endl;
}
