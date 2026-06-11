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
        int a,b; cin >> a >> b;
        for(int i=a; i<=b; i++)
        {
            if(i%n==0){ cout << "OK"; return 0; }
        }
        cout << "NG";
    }
    return 0;
}
    