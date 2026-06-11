/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    ll a,b,n;
    cin>>a>>b>>n;
    ll x = min(b-1,n);
    ll res = floor((a*x)/b) - a*floor(x/b);
    cout<<res<<endl;
    return 0;
}

