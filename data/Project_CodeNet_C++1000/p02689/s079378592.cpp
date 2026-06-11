//#include<bits/stdc++.h> using namespace std;
#include<iostream>
using namespace std;
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue> //priority_queue inside queue
#include<deque>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
#define f(i,start,end) for(i=start;i<=end;i++)
#define min_heap priority_queue<int, vector<int>, greater<int> >
#define max_heap priority_queue<int>

bool isPrime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
} //returns true if prime!

bool bl[200001];

int main()
{
    fast;
//int t=0,tc=0; cin >> tc; f(t,1,tc) //testcases
    {
        ll n, m; cin >> n >> m;
        ll h[n+1]; int i=0,a=0,b=0; f(i, 1, n) cin >> h[i];
        f(i, 0, m-1)
        {
          cin >> a >> b;
          if(h[a]<h[b]){
            if(!bl[a]){
              bl[a]=1; n--;
            }
          }
          else if(h[a]>h[b]){
            if(!bl[b]){
              bl[b]=1; n--;
            }
          }
          else if(h[a]==h[b]){
            if(!bl[b]){
              bl[b]=1; n--;
            }
            if(!bl[a]){
              bl[a]=1; n--;
            }
          }
        }
        cout << n << nl;
    }
    return 0;
}
    