#include <iostream>

#include <deque>

#include <stdio.h>

#include <cstdio>

#include <algorithm>

#include<bits/stdc++.h>

#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define sp <<" "
#define nw <<"\n"
#define ca "Case "<<tc++<<": "
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define ull unsigned LL
#define check cout<<"* ";
#define show_vector(i) for(int q=0;q<i.size();q++){cout<<i[q]<<" ";}
#define REP(i,n) for (int i=0;i<(n);++i)
#define N_MAX 26
#define rep(i, a, b) for(int i = a; i < b; i++)

const int inf=1<<30;
const long long int INF=1e10;
const int MOD=1e9+7;
const int maxn = 1e5+10;
int a[200005],b[1000005];

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/*
int ck_prime(int n)
{
    int coun;
     coun=0;
     if(n>1){
      for(int i=2;i*i<=n;i++){
        if( n%i==0 ){
            coun++;
            break;
          }
        }
      }
     if(n==1){
       coun=coun;
         }
    if(coun==0){
           return 1; // n is prime
        }
    return 0;
}
*/
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1), b(n);
    rep(i, 0, n+1 ) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    long long int sum=0;
    rep(i, 0, n){
        int x=min(a[i],b[i]);
        sum+=x;
        a[i]=a[i]-x;
        b[i]=b[i]-x;
        x=min(a[i+1],b[i]);
        sum+=x;
        a[i+1]=a[i+1]-x;
        b[i]=b[i]-x;
    }
    cout<<sum nw;
}

