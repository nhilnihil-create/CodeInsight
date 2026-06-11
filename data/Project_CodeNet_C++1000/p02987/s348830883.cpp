#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    string s;
    cin>> s;

    if( count (s.begin(), s.end(),s[0])== 2  && count (s.begin(), s.end(),s[1])== 2  && count (s.begin(), s.end(),s[2])== 2  && count (s.begin(), s.end(),s[3])== 2  )
cout << "Yes";
else
    cout << "No";
nl;

    return 0;
}


