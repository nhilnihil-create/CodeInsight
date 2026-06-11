#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb pushback
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,j,n) for(int i=j;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)


int main() {
    int n;
    ll ans;
	cin >> n;
    ll a[10][10];
    fr(i,10){
    	fr(j,10){
        	a[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
    	int j=i;
        if(i<10)a[j][j]++;
        else if(i<100)a[j/10][j%10]++;
        else if(i<1000)a[j/100][j%10]++;
        else if(i<10000)a[j/1000][j%10]++;
        else if(i<100000)a[j/10000][j%10]++;
        else if(i<1000000)a[j/100000][j%10]++;
    }
    fr(i,10){
    	fr(j,10){
        	ans+=a[i][j]*a[j][i];
        }
    }
      cout << ans << endl;
}
