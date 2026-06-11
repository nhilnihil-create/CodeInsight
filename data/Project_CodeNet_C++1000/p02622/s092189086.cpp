//:::: Alien :::://
// Muhammad Eid //
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define prINT pair<int, int>

//const int N = 1e3 +5;

void Mo35(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

int main(){
Mo35();

    string s ,t; cin>> s>> t;
    int c = 0, sz = s.size();
    for(int i=0; i<sz; ++i) if(s[i] != t[i]) c++;
    cout<< c;

return 0;
}
