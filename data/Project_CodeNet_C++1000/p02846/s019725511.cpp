using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;

ll plmi(ll a){
    if(a<0) return -1;
    else if(a==0) return 0;
    else if(a>0) return 1;
}


signed main(){
    ll t1,t2,a1,a2,b1,b2;
    ll s1,s2,p1,p2,an;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    s1 = t1*a1 + t2*a2;
    s2 = t1*b1 + t2*b2;
    p1 = t1*(a1-b1);
    p2 = s1-s2;
    if(p2==0)  cout<<"infinity"<<endl;
    else{
        if(plmi(p1)*plmi(p2)>0) cout<<"0"<<endl;
        else{
            if(abs(p1)%abs(p2)==0){
                an = 2*(abs(p1)/abs(p2));
                cout<<an<<endl;
            }else{
                an = 2*(abs(p1)/abs(p2))+1;
                cout<<an<<endl;
            }
        }
    }
}
