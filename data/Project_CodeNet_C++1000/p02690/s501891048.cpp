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


int main()
{
    fast;
//int t=0,tc=0; cin >> tc; f(t,1,tc) //testcases
    {
       int n; cin >> n;
       ll tmp = 1, tmp2=2;
       while(true)
       {
          if(  (tmp2*tmp2*tmp2*tmp2*tmp2)-(tmp*tmp*tmp*tmp*tmp)<=n ){ tmp2+=1; tmp+=1; }
          else break;
       }
       
        int i=0, j=0;
        f(i, -tmp+1, tmp)
        f(j, -tmp, i-1)
        {
            if((i*i*i*i*i)-(j*j*j*j*j)==n)
            { cout << i << ' ' << j << nl; return 0; }
        }  
    }
    return 0;
}
    