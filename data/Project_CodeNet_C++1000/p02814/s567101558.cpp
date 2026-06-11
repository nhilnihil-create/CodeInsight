#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;

int t;

ull lcm(ull a, ull b){
    return (a*b)/__gcd(a,b);
}

ull number_times_divided_by_two(ull a){
    ull cnt=0;
    while(a%2==0){
        a/=2;
        cnt++;
    }
    return cnt;
}

void solve(){
    ull n, m;
    cin>>n>>m;
    vector<ull> a(n);
    map<int,bool> mark;
    for(int i=0;i<(int)n;i++){
        cin>>a[i];
        a[i]/=2;
        mark[number_times_divided_by_two(a[i])]=true;
    }
    if(mark.size()>1){cout<<0<<endl;return;}
    ull LCM=1;
    for(auto it:a){
        LCM=lcm(LCM,it);
    }
    cout<<(m/LCM+1)/2<<endl;
}

int main()
{
    //freopen("IN.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}