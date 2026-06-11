#include<bits/stdc++.h>
#define endl  "\n"
#define ll long long
#define PI acos(-1.0)
#define test cout<<"\n****\n"
#define precise fixed(cout);cout<<setprecision(12)
#define fast  ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using  namespace  std;


int main(){

    fast;

    string str;
    cin>>str;

    string res = "";

    for(int i=0;i<str.size();i++){
        res = res + 'x';
    }

    cout<<res;

    return 0;
}
