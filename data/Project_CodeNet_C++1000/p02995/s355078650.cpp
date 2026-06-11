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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll e = (c*d)/__gcd(c,d);
    ll n = b-a+1;
    
    ll n_cid,n_c,n_d;

    if(a%e==0)  n_cid = (b/e - a/e)+1;
    else        n_cid = b/e - a/e;

    if(a%c==0)  n_c = (b/c - a/c)+1;
    else        n_c = b/c - a/c;

    if(a%d==0)  n_d = (b/d - a/d)+1;
    else        n_d = b/d - a/d;

    ll res = n - (n_c + n_d - n_cid);

    cout<<res<<endl;
    /*
    if(a%e==0)  i=a;
    else        i=a+e-(a%e);
    //ll m=2;
    while(i<=b){
        cnt++;
        i+=e;
      //  m++;
    }

    if(a%c==0)  i=a;
    else        i=a+c-(a%c);
    //m=2;
    while(i<=b){
       if(i%e!=0)   cnt++;
        i+=c;
      //  m++;
    }

    if(a%d==0)  i=a;
    else        i=a+d-(a%d);
    //m=2;
    while(i<=b){
        if(i%e!=0)  cnt++;
        i+=d;
        //m++;
    }
    ll res = n-cnt;
    cout<<res<<endl;
    */
    return 0;
}

