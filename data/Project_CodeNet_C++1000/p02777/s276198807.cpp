#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){

    string s,t;
    int a,b;
    string u;
    cin >>s>>t>>a>>b>>u;

    if(s==u) a-=1;
    if(t==u) b-=1;

    cout << a << " " << b << endl;

     return 0;
}