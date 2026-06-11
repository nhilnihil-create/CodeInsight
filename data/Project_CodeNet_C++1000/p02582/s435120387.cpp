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

     if(str[0]=='R' && str[1]=='R' && str[2]=='R'){
        cout<<"3\n";
    }
    else if((str[0]=='R' && str[1]=='R') || (str[1]=='R' && str[2]=='R')){
        cout<<"2\n";
    }
     else if(str[0]=='R' || str[1]=='R' || str[2]=='R'){
        cout<<"1\n";
    } else{
        cout<<"0\n";
    }
    return 0;
}
