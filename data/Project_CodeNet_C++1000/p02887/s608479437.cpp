#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=1;
    REPS(i,n-1)
    {
        if(s[i]==s[i-1])
        continue;
        else c++;
    }
    cout<<c;
}