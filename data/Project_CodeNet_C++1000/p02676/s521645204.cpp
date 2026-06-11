// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2e5;

int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int k;
    cin>>k;

    string s;
    cin>>s;
    cout<<s.substr(0,min( k , (int)s.len ) );
    if (k<s.len) cout<<"...";
}
