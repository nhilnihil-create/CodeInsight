//Author: A_S_M_M@sud_P@rvez
#include<bits/stdc++.h>
using namespace std;
#define    MP ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define    for0(i,n) for(int i=0;i<n;i++)
#define    fors(i,s) for(int i=0;i<s.size();i++)
#define    gcd(a, b) __gcd(a , b)
#define    lcm(a,b) (a*(b/__gcd(a,b)))
#define    nl     "\n"
#define    End    return 0
#define    gt     greater<int>()
#define    ll     long long int
#define    mp     make_pair
#define    pb     push_back
#define    vi     vector<int>
#define    vl     vector<ll>
#define    mod    1000000007
#define    ull    unsigned long long int
#define    sp(n)  fixed<<setprecision(n)
#define    pi     acos(-1)

int main()
{
MP;

string s;
cin>>s;
if(s.size()>=3){
    for(int i=0;i<3;i++){
        cout<<s[i];
    }
}else{
    cout<<s;
}

End;   
}