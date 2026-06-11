#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
int main(){
    string str;
    cin>>str;
    if(str[0]=='R' && str[1]=='R' && str[2]=='R')
     cout<<3<<endl;
    else if((str[0]=='R' && str[1]=='R') ||(str[1]=='R' && str[2]=='R'))
     cout<<2<<endl;
    else if(str[0]=='R' || str[1]=='R' || str[2]=='R')
     cout<<1<<endl;
    else
     cout<<0<<endl;
}
