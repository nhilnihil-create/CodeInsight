#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int N;
    cin >> N;

    vector<int> t(N);
    vector<string> s(N);

    REP(i, N){
        cin>> s[i] >> t[i];
    }

    string X;
    cin >> X;

    int cnt=0;
    REP(i, N){
        if(s[i]==X) cnt=i;
    }
    int ans=0;
    REP2(i, cnt+1, N){
        ans+=t[i];
    }

    
    cout << ans << endl;



   return 0;
}