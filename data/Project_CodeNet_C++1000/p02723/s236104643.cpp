#include<bits/stdc++.h>
#define endl  "\n"
#define ll long long
#define PI acos(-1.0)
#define test cout<<"\n****\n"
#define precise fixed(cout);cout<<setprecision(12)
#define fast  ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using  namespace  std;


int main(){

    string str;
    cin>>str;

    if(str[2]==str[3] && str[4]==str[5]){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}