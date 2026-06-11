#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int a[maxn];
int cnt[maxn];

 int getSum(int n) 
    {  
    int sum = 0; 
    while (n != 0) 
    { 
     sum = sum + n % 10; 
     n = n/10; 
    }  
 return sum; 
 }

int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	int a,b;
	cin >> a >> b;
	cout << 6 - a -b << "\n";
}




/*void solve(){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        cout<<x<<" "<<y<<"\n";
        for(int i=1;i<=n;i++){
            if(i!=x)
                cout<<i<<" "<<y<<"\n";
        }
        int dir=0;
        for(int i=1;i<=m;i++){
            if(i==y)
                continue;
            if(dir==0){
                cout<<n<<" "<<i<<"\n";
                for(int j=n-1;j>=1;j--)
                    cout<<j<<" "<<i<<"\n";
                dir=1;
            }
            else{
                cout<<1<<" "<<i<<"\n";
                for(int j=2;j<=n;j++)
                    cout<<j<<" "<<i<<"\n";
                dir=0;
            }
        }
    }
    */