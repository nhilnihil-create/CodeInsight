    #include<bits/stdc++.h>
    using namespace std;
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define REP(i,x) for(int i=0;i<(int)(x);i++)
    #define REPS(i,x) for(int i=1;i<=(int)(x);i++)
    #define mp(a,b) make_pair(a, b)
    #define pb push_back
    #define eb emplace_back
    #define ll long long
    #define MAX 10000000
    int main()
    { int n;
    cin>>n; int ar[n]; ll s=0;
    REP(i,n)
    {
        cin>>ar[i];
        if(i>=1 && ar[i]<ar[i-1]) { int c=abs(ar[i]-ar[i-1]); s+=c; ar[i]+=c;}
    }
    cout<<s<<endl;
    }