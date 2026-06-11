#include<bits/stdc++.h>
#define ll  long long
#define pp pair<int,int>
#define ppn pair<pp,int>
#define F first
#define S second
#define N 1000005
#define mod 1000000007
#define pi 3.14159265358979323846

using namespace std;

int dp[1000001];
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    map<int,int>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
        dp[a[i]]++;
    }
    bool f = true;
    int ans =0;
    for(int i=2; i<1000001; i++){
        int c = 0;
        for(int j=1; j*i<1000001; j++){
            c+=dp[i*j];
        }
        if(c>1){
            f=false;
            //break;
        }
        ans = max(ans,c);
    }
    if(f)cout<<"pairwise coprime"<<endl;
    else cout<<(ans==n?"not coprime":"setwise coprime")<<endl;
}
