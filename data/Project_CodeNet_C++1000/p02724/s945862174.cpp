#include<bits/stdc++.h>
#define endl  "\n"
#define ll long long
#define PI acos(-1.0)
#define test cout<<"\n****\n"
#define precise fixed(cout);cout<<setprecision(12)
#define fast  ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using  namespace  std;


int main(){


    double n;
    cin>>n;

    ll res = 0;

    if(n/500>0){
        ll temp = floor(n/500);
        res = temp*1000;

        n = n - temp*500;

        if(n/5>0){
            ll temp2 = floor(n/5);
            res = res + (temp2*5);
        }
    } else{
        if(n/5>0){
            ll temp2 = floor(n/5);
            res = res + (temp2*5);
        }
    }

    cout<<res;




    return 0;
}