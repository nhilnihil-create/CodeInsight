


#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define inf    0x3f3f3f3f
#define ll long long
#define pb push_back
#define upperlimit 1000100
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]

int main(){

 ll h,w;
 cin>>h>>w;

 ll total = h*w;

 if(h>w) swap(h,w);
 
 if(h == 1)
      cout<<"1"<<endl;
 else 
      cout<<(h*w+1)/2<<endl;


return 0;
}