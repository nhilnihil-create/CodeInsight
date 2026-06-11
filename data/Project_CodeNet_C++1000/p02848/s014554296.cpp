#include <bits/stdc++.h>
typedef long long ll;
#define MAX_N 51
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int l;
    l = s.length();
    for(int i = 0; i<l; i++){
        int t = (s[i] - 'A');
        t+=n;
        t%=26;
        putchar(t+'A');
    }
    cout<<endl;

    return 0;
}