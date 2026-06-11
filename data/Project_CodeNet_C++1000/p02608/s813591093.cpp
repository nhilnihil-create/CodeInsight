#include<bits/stdc++.h>
#define N 200050
#define M 200
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
#define MOD mod
using namespace std;
int ar[N];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int ans = 0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=1;k<=100;k++){
                ar[(i*i)+(j*j)+(k*k)+(i*j)+(j*k)+(i*k)]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ar[i]<<" ";
  	return 0;
}

