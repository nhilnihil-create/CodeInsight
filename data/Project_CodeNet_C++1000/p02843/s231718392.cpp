//
//  main.cpp
//  Atcoder1
//
//  Created by Hamske on 2020/09/17.
//  Copyright © 2020 Author. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

//#define pb push_back
//#define mp make_pair
//
//#define F first
//#define S second

typedef long long ll;

#define rept(_i,iv,n,type) for(type _i=(type)(iv);_i<(type)(n);++_i)
//#define repi(_i,iv,n) rept(_i,iv,n,int)
//#define repl(_i,iv,n) rept(_i,iv,n,ll)

#define rept0(_i,n,type) rept(_i,0,n,type)
#define repi0(_i,n) rept(_i,0,n,int)
#define repl0(_i,n) rept(_i,0,n,ll)

//#define repst(_i,iv,n,type) for(type _i=iv;_i<=(type)(n);++_i)
//#define repsi1(_i,n) repst(_i,1,n,int)

#define REPT(_i,iv,_l,n,type) for(type _i=(type)(iv),_l=(type)(n);_i<_l;++_i)
//#define REPI(_i,iv,_l,n) REPT(_i,iv,_l,n,int)
//#define REPL(_i,iv,_l,n) REPT(_i,iv,_l,n,ll)
//
#define REPT0(_i,_l,n,type) REPT(_i,0,_l,n,type)
#define REPI0(_i,_l,n) REPT(_i,0,_l,n,int)
#define REPL0(_i,_l,n) REPT(_i,0,_l,n,ll)


//#define rrept(_i,x,e,type) for(type _i=((type)(x)-1);_i>=e;--_i)
//
//#define rrept0(_i,x,type) rrept(_i,x,0,type)
//
//#define RREPT(_i,x,_e,e,type) for(type _i=((type)(x)-1),_e=(type)(e);_i>=_e;--_i)
//
//#define RREPT0(_i,x,_e,type) RREPT(_i,x,_e,0,type)
//
//#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

//#define all(x) (x).begin(),(x).end()
#define REPV(v,_itr,_end) for(auto _itr=(v).begin(),_end=(v).end();_itr!=_end;++_itr)
#define REPVC(v,_itr,_end) for(auto _itr=(v).cbegin(),_end=(v).cend();_itr!=_end;++_itr)

#define td typedef
//#define tds(stl,type,name) typedef stl<type > name;
#define tdv(type,name) typedef vector<type > name;


//typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb > vvb;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<ll> vll;
//typedef vector<vll > vvll;

#define mod99 998244353

int main(int argc, const char * argv[]) {
    int X;
    cin>>X;
    int mod=X%100;
    repi0(i2, 50){
        int s2=i2*2;
        repi0(i3, 34){
            int s3=s2+i3*3;
            repi0(i4, 25){
                int s4=s3+i4*4;
                repi0(i5, 20){
                    int s=s4+i5*5;
                    int i1;
                    if(mod<s){
                        i1=(s-mod)%100;
                    }else{
                        i1=mod-s;
                    }
                    int sum=i1*101+i2*102+i3*103+i4*104+i5*105;
                    if(sum<=X){
                        cout<<1<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<0<<endl;
    
    return 0;
}
