#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 105
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
ll gcd(ll a,ll b) {
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b) {
    return a*b/gcd(a,b);
}
ll a,b,c,d,sum,ans,ans1;
int main() {
	cin>>a>>b>>c>>d;
	sum=lcm(c,d),a--;
	ans=a/c+a/d-a/sum;
	ans1=b/c+b/d-b/sum;
	cout<<b-a-ans1+ans;
	return 0;
}