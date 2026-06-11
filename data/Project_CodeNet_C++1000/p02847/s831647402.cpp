#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(15)
#define c2i(c) {i-48;}
#define i2c(n) {n+48;}

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

int main(){
    int m,n,cnt=0;
    string s;

    cin >> s;
    int res;
    if(s=="SUN") res=7;
    else if(s=="MON") res=6;
    else if(s=="TUE") res=5;
    else if(s=="WED") res=4;
    else if(s=="THU") res=3;
    else if(s=="FRI") res=2;
    else if(s=="SAT") res=1;
    cout << res << endl;
}
